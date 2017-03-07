/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cnn.h
 * Author: rif
 *
 * Created on March 6, 2017, 2:43 PM
 */

#ifndef CNN_H
#define CNN_H

#include <opencv2/core.hpp>

#include "DataPreparation.h"

using namespace cv;

class cnn {
public:
    cnn(Size size_input, Size size_local_field, int number_of_feature_maps);
    cnn(const cnn& orig);
    virtual ~cnn();
    
    void convolutional_layer(Mat local_field_of_imsource, Mat weights_of_local_field);
    void initialization_weights();
    void initialization_biases();
    
    void train_data(DataPreparation *data);
private:
    int number_of_feature_maps;
    Mat *weights_of_feature_maps;
    Mat biases_of_feature_maps;
    Mat conv_layer;
    Mat pool_layer;
    
    Size size_of_input_neurons;
    Size size_of_local_field;
    Size size_of_conv;
    Size size_of_pool;
    Size size_of_output_neurons;
};

#endif /* CNN_H */

