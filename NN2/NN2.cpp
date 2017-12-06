/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NN2.cpp
 * Author: rif
 * 
 * Created on February 27, 2017, 5:05 PM
 */

#include "NN2.h"
#include "Sigmoid.h"

NN2::NN2(DataPreparation *data, int * layers, int length_of_layers) {
    this->nn.data = data;
    this->nn.layers = layers;
    this->nn.length_of_layers = length_of_layers;
    this->nn.Initialize();
}

NN2::NN2(const NN2& orig) {
}

NN2::~NN2() {
}

void NN2::sgd(int epochs, int mini_batch_size, double learning_rate) {
    int n_test = nn.data->number_of_test_data;
    int n = nn.data->number_of_train_data;
    
    vector<Mat> mini_batch_train;
    vector<Mat> mini_batch_train_label;
    
    mini_batch_train.reserve(mini_batch_size);
    mini_batch_train_label.reserve(mini_batch_size);
    
    for(int i=0; i<epochs; ++i) {
        for(int j=0; j<n/mini_batch_size; ++j) {
            for(int z=0; z<mini_batch_size; ++z) {
                mini_batch_train.push_back(nn.data->train_vectors[j*mini_batch_size+z]);
                mini_batch_train_label.push_back(nn.data->train_labels[j*mini_batch_size+z]);
            }
            update_mini_batch(mini_batch_train,mini_batch_train_label, mini_batch_size, learning_rate);
            mini_batch_train.clear();
            mini_batch_train_label.clear();
        }
        
        //evaluate
        int n_eval = evaluate(nn.data);
        cout << "Epoch " << i << ": " << n_eval << "/" << n_test << endl;
    }
    
}

void NN2::update_mini_batch(vector<Mat> mini_batch_train, vector<Mat> mini_batch_train_label, int mini_batch_size, double learning_rate) {
    
    for(int i=0; i<mini_batch_size; ++i) {
        backprop(mini_batch_train[i],mini_batch_train_label[i]);
    }
    
    for(int i=0; i<nn.length_of_layers-1; ++i) {
        nn.weights[i] = nn.weights[i] - (learning_rate/mini_batch_size) * nn.nabla_weights[i];
        nn.biases[i] = nn.biases[i] -  (learning_rate/mini_batch_size) * nn.nabla_biases[i];
    }
}

void NN2::backprop(Mat train_images, Mat train_labels) {
    // convert unsigned char to double
    Mat train_images_double(train_images.rows*train_images.cols,1, CV_64FC1, Scalar::all(0));
    train_images.convertTo(train_images_double,CV_64FC1);
    Mat train_labels_double(train_labels.rows*train_labels.cols,1, CV_64FC1, Scalar::all(0));
    train_labels.convertTo(train_labels_double,CV_64FC1);
    
    // feed forward
    Mat activation = train_images_double.clone();
    nn.activations[0] = activation;
    
    for(int i=1; i<nn.length_of_layers; ++i) {
        Mat z(nn.layers[i],1, CV_64FC1, Scalar::all(0));
        z = (nn.weights[i-1] * activation) + nn.biases[i-1];
        
        nn.zs[i-1] = z;
        
        activation.deallocate();
        activation = z.clone();
        activation = Sigmoid::Compute(z);
        
        
        nn.activations[i] = activation;
    }
    
    // backward pass
    Mat delta = cost_derivative(nn.activations[nn.length_of_layers-1],train_labels_double).mul(Sigmoid::ComputePrime(nn.zs[(nn.length_of_layers-1)-1]));
    
    cout << delta << endl;
    
    nn.nabla_biases[(nn.length_of_layers-1)-1] = delta;
    nn.nabla_weights[(nn.length_of_layers-1)-1] = delta * nn.activations[nn.length_of_layers-2].t();
    
    for(int l=2; l<nn.length_of_layers; ++l) {
        Mat delta_temp = delta.clone();
        delta.deallocate();
        delta = (nn.weights[(nn.length_of_layers-1)-l+1].t() * delta_temp).mul(Sigmoid::ComputePrime(nn.zs[(nn.length_of_layers-1)-l]));
        
        nn.nabla_biases[(nn.length_of_layers-1)-l] = delta;
        nn.nabla_weights[(nn.length_of_layers-1)-l] = delta * nn.activations[nn.length_of_layers-l-1].t();
    }
}

Mat NN2::cost_derivative(Mat output_activations, Mat y_target) {
    return output_activations-y_target;
}

int NN2::evaluate(DataPreparation* data) {
    int  n_test = data->number_of_test_data;
    int eval = 0;
    for(int i=0; i<n_test; ++i) {
        
        Mat ff = feed_forward(data->test_vectors[i]);
        
        
        double max_val_a,min_val_a;
        Point max_loc_a,min_loc_a;
        minMaxLoc(ff,&min_val_a,&max_val_a,&min_loc_a,&max_loc_a);
        
        double max_val,min_val;
        Point max_loc,min_loc;
        Mat label = data->test_labels[i];
        minMaxLoc(label,&min_val,&max_val,&min_loc,&max_loc);
        
        
        
        if(max_loc_a == max_loc) {
            eval += 1;
        }
    }
    
    return eval;
}

Mat NN2::feed_forward(Mat test_images) {    
    Mat a = test_images.clone(); 
    for(int i=0; i<nn.length_of_layers-1; ++i) {
        Mat z = (nn.weights[i] * a) + nn.biases[i]; 
        a.deallocate();
        a = z.clone();
        a = Sigmoid::Compute(z);
    }
    return a;
}








