/*
 * Copyright (C) INFOGLOBAL TEKNOLOGI SEMESTA, PT - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential.
 */

/* 
 * File:   Layer.h
 * Author: RIF <arif.lazuardi@infoglobal.co.id>
 *
 * Created on March 24, 2017, 1:48 PM
 */

#ifndef LAYER_H
#define LAYER_H

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

#include "Activation.h"


using namespace std;
using namespace cv;


typedef enum {convolution,pooling,fully_connected} layer_type;

class Layer {
public:
    //layer_type type;
    Mat weights;
    Mat biases;
    Mat weights_update;
    Mat biases_update;
    Mat x;                  //input
    Mat z;                  //output
    Mat a;                  //activated
    Mat e;                  //error
    Mat delta;              //delta
    Mat od;                 //output delta
    Activation* activation;
    layer_type type;
    
    virtual void intialization(Size input_size, int input_type, Size output_size, int output_type) = 0;
    virtual void set_weights(Mat weights) = 0;
    virtual void set_biases(Mat biases) = 0;
    virtual void feed_forward(Mat x) = 0;
    virtual void back_pass(Mat y) = 0;
    virtual void apply_gradient(double alpha) = 0;
private:
    
    virtual void compute_z() = 0;
    virtual void compute_a() = 0;
    virtual void compute_delta() = 0;
    virtual void compute_gradient() = 0;
};

#endif /* LAYER_H */

