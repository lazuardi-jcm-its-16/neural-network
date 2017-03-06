/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cnn.cpp
 * Author: rif
 * 
 * Created on March 6, 2017, 2:43 PM
 */

#include "cnn.h"

cnn::cnn(DataPreparation *data, Size size_input, Size size_local_field, int number_of_feature_maps) {
    size_of_input_neurons = size_input;
    size_of_local_field = size_local_field;
    
    size_of_conv.width = size_of_input_neurons.width - size_local_field.width + 1;
    size_of_conv.height = size_of_input_neurons.height - size_of_local_field.height + 1;
    
    size_of_pool.width = size_of_conv.width/2;
    size_of_pool.height = size_of_conv.height/2;
    
    size_of_output_neurons.width = 1;
    size_of_output_neurons.height = 10;
    
    weights = new Mat[size_of_conv.width*size_of_conv.height];
    for(int i=0; i<size_of_conv.width*size_of_conv.height; ++i) {
        Mat temp_weights = Mat::zeros(size_of_local_field.width,size_of_local_field.height, CV_64FC1);
        randn(temp_weights,0,1);
        weights[i] = temp_weights;
    }
    
    biases = Mat::zeros(1,number_of_feature_maps, CV_64FC1);
    randn(biases,0,1);
    
    for(int i=0; i<data->number_of_train_data; ++i) {
        Mat input = data->train_images[i]->clone();
        for(int x=0; x<size_of_conv.width; ++x) {
            for(int y=0; y<size_of_conv.height; ++x) {
                
            }
        }
    }
}

cnn::cnn(const cnn& orig) {
}

cnn::~cnn() {
}

