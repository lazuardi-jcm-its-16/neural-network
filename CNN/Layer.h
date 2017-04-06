/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Layer.h
 * Author: rif
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
    Mat x;
    Mat z;
    Mat a;
    Activation* activation;
    layer_type type;
    
    virtual void feed_forward(Mat x) = 0;
    virtual void intialization() = 0;
private:
    
    virtual void compute_z() = 0;
    virtual void compute_a() = 0;
};

#endif /* LAYER_H */

