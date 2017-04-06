/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LayerConvolution.cpp
 * Author: rif
 * 
 * Created on March 24, 2017, 2:01 PM
 */

#include "LayerConvolution.h"

LayerConvolution::LayerConvolution(int number_of_feature, int kernel_size, int stride, Activation* act) : Layer() {
    this->type = convolution;
    
    this->number_of_feature = number_of_feature;
    this->kernel_size.height = kernel_size;
    this->kernel_size.width = kernel_size;
    this->stride = stride;
    this->activation = act;
    
    point_conv.x = 0;
    point_conv.y = 0;
}


LayerConvolution::~LayerConvolution() {
}

void LayerConvolution::intialization() {
    weights.create(kernel_size,CV_32FC(number_of_feature));
    randn(weights,0,1);
    
    biases.create(1,number_of_feature,CV_32F);
    randn(biases,0,1);
}

void LayerConvolution::feed_forward(Mat x) {
    this->x = x;
    compute_z();
    compute_a();
}

void LayerConvolution::compute_z() {
    vector<Mat> z_channels;
    z.create(x.rows-kernel_size.height+1, x.cols-kernel_size.width+1, CV_32FC(number_of_feature));
    for(int i=0; i<number_of_feature; i++) {
        Mat o = Mat::zeros(x.rows, x.cols, CV_32F);
        Mat kernel(kernel_size,CV_32F);
        extractChannel(weights,kernel,i);
        
        filter2D(x,o,CV_32F,kernel,point_conv,0.0,BORDER_ISOLATED);

        z_channels.push_back(o.colRange(0, o.cols - (kernel_size.width-1)).rowRange(0, o.rows - (kernel_size.height-1)));
    }
    merge(z_channels,z);
}

void LayerConvolution::compute_a() {
    a = activation->compute(z);
}



