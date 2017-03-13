/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DNN.cpp
 * Author: rif
 * 
 * Created on March 8, 2017, 5:11 PM
 */

#include "DNN.h"

DNN::DNN() {
    cv::dnn::Net net;
    cv::dnn::ConvolutionLayer conv;
    cv::dnn::PoolingLayer pool;
    cv::dnn::InnerProductLayer fully_connected;
    
    cv::Size kernel_size(5,5);
    cv::Size stride_size(1,1);
    cv::Size pad_size(0,0);
    cv::Size dilation_size(1,1);
    conv.create(kernel_size,stride_size,pad_size,dilation_size);
}

DNN::DNN(const DNN& orig) {
}

DNN::~DNN() {
}

