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

cnn::cnn(Size size_input, Size size_local_field, int number_feature_maps) {
    // jumlah feature maps di setiap hidden layer
    number_of_feature_maps = number_feature_maps;
    
    // ukuran matriks neuron input
    size_of_input_neurons = size_input;
    
    // ukuran matriks local field (untuk konvolusi)
    size_of_local_field = size_local_field;
    
    // ukuran matriks layer konvolusi (hasil dari local_field * weight_of_local_field + bias)
    size_of_conv.width = size_of_input_neurons.width - size_local_field.width + 1;
    size_of_conv.height = size_of_input_neurons.height - size_of_local_field.height + 1;
    conv_layer.create(size_of_conv,CV_64FC(number_of_feature_maps));
    
    // ukuran matriks layer pool (hasil dari layer konvolusi
    size_of_pool.width = size_of_conv.width/2;
    size_of_pool.height = size_of_conv.height/2;
    pool_layer.create(size_of_pool,CV_64FC(number_of_feature_maps));
    
    // ukuran matriks neuron output
    size_of_output_neurons.width = 1;
    size_of_output_neurons.height = 10;
    
    
    
    initialization_weights();
    initialization_biases();
    
    cout << weights_of_feature_maps[0].at<Vec2f>(0,0)[19] << endl;
    cout << biases_of_feature_maps.at<Vec2f>(0,0)[19] << endl;
}

cnn::cnn(const cnn& orig) {
}

cnn::~cnn() {
}

void cnn::initialization_weights() {
    // inisiasi weights untuk layer input sebanyak jumlah feature_maps matriks konvolusi layer
    weights_of_feature_maps = new Mat[number_of_feature_maps];
    
    for(int i=0; i<number_of_feature_maps; ++i) {
        // inisiasi weights untuk layer input (sebanyak jumlah neuron/pixel di matriks konvolusi)
        // untuk setiap neuron di matriks konvolusi memiliki matriks weight dengan ukuran local_field
        Mat weights(size_of_local_field, CV_64FC(size_of_conv.area()));
        randn(weights,0,1);

        weights_of_feature_maps[i] = weights;
    }   
}

void cnn::initialization_biases() {
    // inisiasi biases untuk layer input sebanyak jumlah feature_maps matriks konvolusi layer
    // inisiasi biases dengan bilangan random distribusi gaussian/normal dengan mean=0 dan std=1
    biases_of_feature_maps.create(1,1, CV_64FC(number_of_feature_maps));
    randn(biases_of_feature_maps,0,1);
}

void cnn::train_data(DataPreparation *data) {
    
    for(int i=0; i<data->number_of_train_data; ++i) {
        Mat input = data->train_images[i];
        
        for(int j=0; j<number_of_feature_maps; ++j) {
            Mat weights_in_single_feature = weights_of_feature_maps[j];
            Mat weights_of_local_field[size_of_conv.area()];
            split(weights_in_single_feature, weights_of_local_field);
            
            for(int x=0; x<size_of_conv.width; ++x) {
                for(int y=0; y<size_of_conv.height; ++x) {
                    
                    Point point(x,y);
                    Rect rect(point,size_of_pool);
                    Mat local_field = input(rect);
                    /*
                    conv_layer.at<Vec2f>(x,y)[i] = sum(local_field.mul(weights_of_local_field[x+y])).val[0] + biases_of_feature_maps.at<Vec2f>(0,0)[i];
                    */
                }
            }
        }
    }
}

