/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NN.cpp
 * Author: rif
 * 
 * Created on February 27, 2017, 5:05 PM
 */

#include "NN.h"
#include "Sigmoid.h"

NN::NN(int * layers, int length_of_layers) {
    this->layers = layers;
    this->length_of_layers = length_of_layers;
    
    biases = new Mat[length_of_layers-1];
    weights = new Mat[length_of_layers-1];
    initialization_biases_and_weights(this->biases, this->weights, true);
}

NN::NN(const NN& orig) {
}

NN::~NN() {
    //delete[] biases;
    //delete[] weights;
}

void NN::initialization_biases_and_weights(Mat * biases, Mat * weights, bool fill_random) {
    for(int i=1; i<length_of_layers; ++i) {
        Mat temp_biases(layers[i],1, CV_64FC1, Scalar::all(0));
        biases[i-1] = temp_biases.clone();
        
        Mat temp_weights(layers[i],layers[i-1], CV_64FC1, Scalar::all(0));
        weights[i-1] = temp_weights.clone();
        
        if(fill_random) {
            RNG rng;
            rng.fill(biases[i-1],RNG::NORMAL,0,1,false);
            rng.fill(weights[i-1],RNG::NORMAL,0,1,false);
        }
    }
}



void NN::sgd(DataPreparation *data, int epochs, int mini_batch_size, double learning_rate) {
    
    int n_test = data->number_of_test_data;
    int n = data->number_of_train_data;
    
    Mat* mini_batch_train = new Mat[mini_batch_size];
    Mat* mini_batch_train_label = new Mat[mini_batch_size];
    for(int i=0; i<epochs; ++i) {
        for(int j=0; j<n/mini_batch_size; ++j) {
            for(int z=0; z<mini_batch_size; ++z) {
                mini_batch_train[z] = data->train_vectors[j*mini_batch_size+z];
                mini_batch_train_label[z] = data->train_labels[j*mini_batch_size+z];
            }
            update_mini_batch(mini_batch_train,mini_batch_train_label, mini_batch_size, learning_rate);
        }
        
        //evaluate
        //int n_eval = evaluate(data);
        //cout << "Epoch " << i << ": " << n_eval << "/" << n_test << endl;
    }
    
}

void NN::update_mini_batch(Mat * mini_batch_train, Mat * mini_batch_train_label, int mini_batch_size, double learning_rate) {
    Mat * nabla_biases = new Mat[length_of_layers-1];
    Mat * nabla_weights = new Mat[length_of_layers-1];
    initialization_biases_and_weights(nabla_biases, nabla_weights, false);
    
    for(int i=0; i<mini_batch_size; ++i) {
        backprop(mini_batch_train[i],mini_batch_train_label[i]);
        
        /*
        for(int j=0; j<length_of_layers-1; ++j) {
            nabla_biases[j] = nabla_biases[j] + delta_nabla.nabla_biases[j];
            nabla_weights[j] = nabla_weights[j] + delta_nabla.nabla_weights[j];
        }*/
    }
    /*
    for(int i=0; i<length_of_layers-1; ++i) {
        weights[i] = (weights[i] - (learning_rate/mini_batch_size)) * nabla_weights[i];
        biases[i] = (biases[i] -  (learning_rate/mini_batch_size)) * nabla_biases[i];
    }*/
}

void NN::backprop(Mat train_images, Mat train_labels) {
    Mat * nabla_biases = new Mat[length_of_layers-1];
    Mat * nabla_weights = new Mat[length_of_layers-1];
    initialization_biases_and_weights(nabla_biases, nabla_weights, false);
    
    // feed forward
    Mat train_images_double(train_images.rows*train_images.cols,1, CV_64FC1, Scalar::all(0));
    train_images.convertTo(train_images_double,CV_64FC1);
    
    Mat activation = train_images_double.clone();
    Mat * activations = new Mat[length_of_layers-1];
    activations[0] = activation;
    Mat * zs = new Mat[length_of_layers-1];
        
    for(int i=1; i<length_of_layers; ++i) {
        Mat z(layers[i],1, CV_64FC1, Scalar::all(0));
        z = (weights[i-1] * activation) + biases[i-1];
        zs[i-1] = z;
        
        activation.deallocate();
        activation = z.clone();
        activation = Sigmoid::Compute(z);
        activations[i] = activation;
    }
    
    // backward pass
    Mat delta = cost_derivative(activations[(length_of_layers-1)-1],train_labels).mul(Sigmoid::ComputePrime(zs[(length_of_layers-1)-1]));
    nabla_biases[(length_of_layers-1)-1] = delta;
    
    Mat act = activations[(length_of_layers-1)-2];
    Mat act_transpose(act.cols,act.rows,act.type());
    transpose(act,act_transpose);
    nabla_weights[(length_of_layers-1)-1] = delta * act_transpose;
    
    for(int l=2; l<length_of_layers; ++l) {
        Mat z = zs[(length_of_layers-1)-l];
        Mat sp = Sigmoid::ComputePrime(z);
        Mat delta_temp = delta.clone();
        delta.deallocate();
        Mat delta = (weights[(length_of_layers-1)-l+1] * delta_temp).mul(sp);
        nabla_biases[(length_of_layers-1)-l] = delta;
        
        Mat act = activations[(length_of_layers-1)-l-1];
        Mat act_transpose(act.cols,act.rows,act.type());
        transpose(act,act_transpose);
        nabla_weights[(length_of_layers-1)-l] = delta * act_transpose;
    }
    
    delta_nabla.nabla_biases = nabla_biases;
    delta_nabla.nabla_weights = nabla_weights;
}

Mat NN::cost_derivative(Mat output_activations, Mat y_target) {
    return output_activations-y_target;
}

int NN::evaluate(DataPreparation* data) {
    int  n_test = data->number_of_test_data;
    int eval = 0;
    for(int i=0; i<n_test; ++i) {
        Mat ff = feed_forward(data->test_images[i]);
        double max_val,min_val;
        Point max_loc,min_loc;
        minMaxLoc(ff,&min_val,&max_val,&min_loc,&max_loc);
        
        Mat label = data->test_labels[i];
        uchar* p = label.ptr();
        if(max_loc.x == p[0]) {
            eval += 1;
        }
    }
    
    return eval;
}

Mat NN::feed_forward(Mat test_images) {
    Mat a = test_images.clone();
    for(int i=0; i<length_of_layers-1; ++i) {
        Mat z = (weights[i] * a) + biases[i];
        a.deallocate();
        a = z.clone();
        a = Sigmoid::Compute(z);
    }
    return a;
}








