/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CNN2.h
 * Author: rif
 *
 * Created on March 6, 2017, 2:43 PM
 */

#ifndef CNN2_H
#define CNN2_H

#define Vec20f Vec<float,20> 

#include <opencv2/core.hpp>
#include "DataPreparation.h"

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

class CNN2 {
public:
    CNN2(Size size_input, Size size_convolution, Size size_pool, Size size_output, int number_feature_maps);
    CNN2(const CNN2& orig);
    virtual ~CNN2();
    
    void initialization_weights();
    void initialization_biases();
    
    void train_data(DataPreparation *data, int epochs);
    void back_propagation(Mat input_train, Mat target_train);
    void convolutional_layer(Mat local_field_of_imsource);
    void pooling_layer(Mat conv_layer_by_index, int index);
    void fully_connected_layer(Mat pool_layer);
    
    Mat cost_derivative(Mat output_activations, Mat y_target);
private:
    int number_of_feature_maps;
    Mat weights_of_feature_maps, weights_of_fully_conn_maps;
    Mat biases_of_feature_maps, biases_of_fully_conn_maps;
    Mat conv_layer;
    Mat pool_layer;
    Mat output_layer;
    
    Mat pool_vector;
    
    Size size_of_input_layer;
    Size size_of_conv_layer;
    Size size_of_pool_layer;
    Size size_of_output_layer;
    
    Size size_of_conv;
    Size size_of_pool;
};

#endif /* CNN2_H */

