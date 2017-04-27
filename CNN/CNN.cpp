/*
 * Copyright (C) INFOGLOBAL TEKNOLOGI SEMESTA, PT - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential.
 */

/* 
 * File:   CNN.cpp
 * Author: RIF <arif.lazuardi@infoglobal.co.id>
 * 
 * Created on April 6, 2017, 4:12 PM
 */

#include "CNN.h"
#include "LayerConvolution.h"
#include "LayerPool.h"
#include "LayerFC.h"

CNN::CNN() {
    alpha = 1.0;
}

CNN::CNN(const CNN& orig) {
}

CNN::~CNN() {
}

void CNN::set_data(DataPreparation* data) {
    this->data = data;
}

void CNN::push_layer(Layer* layer) {
    layers.push_back(layer);
}

void CNN::initialization() {
    Size input_size, output_size;
    int input_type, output_type;
    number_of_layers = layers.size();
    
    for(int i=0; i<number_of_layers; i++) {
        switch(layers[i]->type) {
            case convolution: {
                LayerConvolution* conv = dynamic_cast<LayerConvolution*>(layers[i]);
                
                input_size.height = (i == 0) ? data->train_images[0].rows : layers[i-1]->a.rows;
                input_size.width = (i == 0) ? data->train_images[0].cols : layers[i-1]->a.cols;
                input_type = (i == 0) ? CV_64FC1 : layers[i-1]->a.type();
                    
                output_size.height = input_size.height - (conv->kernel_size.height-1);
                output_size.width = input_size.width - (conv->kernel_size.width-1);
                output_type = CV_64FC(conv->number_of_feature);
                break;
            }
            case pooling: {
                LayerPool* pool = dynamic_cast<LayerPool*>(layers[i]);
                
                input_size.height = layers[i-1]->a.rows;
                input_size.width = layers[i-1]->a.cols;
                input_type =layers[i-1]->a.type();
                
                output_size.height = input_size.height / pool->pool_size.height;
                output_size.width = input_size.width / pool->pool_size.width;
                output_type = input_type;
                break;
            }  
            case fully_connected: {
                LayerFC* fc = dynamic_cast<LayerFC*>(layers[i]);
                
                input_size.height = layers[i-1]->a.rows * layers[i-1]->a.cols * layers[i-1]->a.channels();
                input_size.width = 1;
                input_type = CV_64FC1;
                
                output_size.height = fc->number_of_neuron_output;;
                output_size.width = 1;
                output_type = CV_64FC1;
                break;
            }
        }
        
        layers[i]->intialization(input_size,input_type,output_size,output_type);
    } 
}

void CNN::train() {
    cout << data->train_labels[169] << endl;
    for(int i=0; i<30; ++i) {
        feed_forward();
        back_pass();
        apply_grads();
    }
    
    Mat input;
    data->train_images[169].convertTo(input,CV_64F);
    input = input / 255.0;
    
    imshow("tes", input);
    waitKey();
    
}

void CNN::feed_forward() {
    Mat input;
    data->train_images[169].convertTo(input,CV_64F);
    input = input / 255.0;
    
    for(int i=0; i<number_of_layers; i++) {
        Mat x = (i == 0) ? input : layers[i-1]->a;
        layers[i]->feed_forward(x);
    }
}

void CNN::back_pass() {
    for(int i=number_of_layers-1; i>=0; i--) {
        Mat target;
        data->train_labels[169].convertTo(target,CV_64F);
        
        Mat delta;
        switch(layers[i]->type) {
            case pooling: {
                if(layers[i+1]->type == fully_connected) {
                    LayerFC* fc = dynamic_cast<LayerFC*>(layers[i+1]);
                    delta = fc->transform_to_image();
                }
                else if(layers[i+1]->type == convolution) {
                    LayerConvolution* conv = dynamic_cast<LayerConvolution*>(layers[i+1]);
                    delta = conv->convolve_full_bp(conv->delta,conv->weights);
                }
                break;
            }
            case convolution: {
                LayerPool* pool = dynamic_cast<LayerPool*>(layers[i+1]);
                delta = pool->pool_up(pool->delta);
                break;
            }
        }
        
        Mat x = (i == number_of_layers-1) ? target : delta;
        layers[i]->back_pass(x);
    }  
}

void CNN::apply_grads() {
    for(int i=0; i<number_of_layers; i++) {
        layers[i]->apply_gradient(alpha);
    }
}








