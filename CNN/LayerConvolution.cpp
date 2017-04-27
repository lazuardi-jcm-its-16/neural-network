/*
 * Copyright (C) INFOGLOBAL TEKNOLOGI SEMESTA, PT - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential.
 */

/* 
 * File:   LayerConvolution.cpp
 * Author: RIF <arif.lazuardi@infoglobal.co.id>
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

LayerConvolution::LayerConvolution(const LayerConvolution& orig) {
}

LayerConvolution::~LayerConvolution() {
}

void LayerConvolution::intialization(Size input_size, int input_type, Size output_size, int output_type) {
    x.create(input_size,input_type);
    z.create(output_size,output_type);
    a.create(output_size,output_type);
    
    weights.create(kernel_size,CV_64FC(x.channels()*number_of_feature));
    randn(weights,0,1);
    float fan_in = x.channels() * pow(kernel_size.height,2);
    float fan_out = z.channels() * pow(kernel_size.height,2);
    weights = (weights - 0.5f)*2.0f*sqrt(6.0f/(fan_in+fan_out));
    
    biases = Mat::zeros(1,number_of_feature,CV_64F);
}

void LayerConvolution::set_weights(Mat weights) {
    this->weights = weights;
}


void LayerConvolution::set_biases(Mat biases) {
    this->biases = biases;
}

void LayerConvolution::feed_forward(Mat x) {
    this->x = x;
    compute_z();
    compute_a();
}

void LayerConvolution::compute_z() {
    z = convolve_valid_ff(x,weights,biases);
}

void LayerConvolution::compute_a() {
    a = activation->compute(z);
}

void LayerConvolution::back_pass(Mat y) {
    e = y;
    compute_delta();
    compute_gradient();
}

void LayerConvolution::compute_delta() {
    od = e.mul(activation->compute_prime(a));
    delta = od;
}

void LayerConvolution::compute_gradient() {
    weights_update = convolve_valid_bp(x,delta);
    
    biases_update.create(1,delta.channels(),CV_64F);
    for(int i=0; i<delta.channels();++i) {
        Mat d(delta.rows,delta.cols,CV_64F);
        extractChannel(delta,d,i);
        biases_update.at<double>(0,i) = sum(d)[0];
    }
}

void LayerConvolution::apply_gradient(double alpha) {
    weights = weights - (weights_update*alpha);
    biases = biases - (biases_update*alpha);
}


Mat LayerConvolution::convolve_valid_ff(Mat inputs, Mat kernels, Mat biases) {
    Size input_size;
    input_size.height = inputs.rows;
    input_size.width = inputs.cols;
    
    Size kernel_size;
    kernel_size.height = kernels.rows;
    kernel_size.width = kernels.cols;
    
    int output_rows = inputs.rows-(kernels.rows-1);
    int output_cols = inputs.cols-(kernels.cols-1);
    Mat output(output_rows,output_cols,CV_64FC(kernels.channels()/inputs.channels()));
    vector<Mat> output_array;
    
    int idx=0;
    for(int om=0; om<kernels.channels()/inputs.channels(); ++om) {
        Mat z = Mat::zeros(output_rows, output_cols, CV_64F);
        for(int im=0; im<inputs.channels(); ++im) {
            Mat input(input_size,CV_64F);
            extractChannel(inputs,input,im);
            
            Mat kernel(kernel_size,CV_64F);
            extractChannel(kernels,kernel,idx++);
            
            z += conv2D(input,kernel,valid);
        }
        output_array.push_back(z + biases.at<double>(0,om));
    }
    
    merge(output_array,output);
    return output;
}

Mat LayerConvolution::convolve_valid_bp(Mat inputs, Mat kernels) {
    Mat flip_inputs;
    
    Size input_size;
    input_size.height = inputs.rows;
    input_size.width = inputs.cols;
    
    Size kernel_size;
    kernel_size.height = kernels.rows;
    kernel_size.width = kernels.cols;
    
    int output_rows = inputs.rows-(kernels.rows-1);
    int output_cols = inputs.cols-(kernels.cols-1);
    Mat output(output_rows,output_cols,CV_64FC(kernels.channels()*inputs.channels()));
    vector<Mat> output_array;
    
    for(int om=0; om<kernels.channels(); ++om) {
        for(int im=0; im<inputs.channels(); ++im) {
            Mat input(input_size,CV_64F);
            extractChannel(inputs,input,im);
            flip(input,flip_inputs,-1);
            
            Mat kernel(kernel_size,CV_64F);
            extractChannel(kernels,kernel,om);
            
            output_array.push_back(conv2D(flip_inputs,kernel,valid));
        }
    }
    
    merge(output_array,output);
    return output;
}


Mat LayerConvolution::convolve_full_bp(Mat inputs, Mat kernels) {
    Mat conv(inputs.rows+(kernels.rows-1),inputs.cols+(kernels.cols-1),CV_64FC(kernels.channels()/inputs.channels()));
    vector<Mat> conv_array;
    
    int idx=0;
    for(int im=0; im<kernels.channels()/inputs.channels(); ++im) {
        Mat z(inputs.rows+(kernels.rows-1),inputs.cols+(kernels.cols-1),CV_64F, Scalar::all(0.0));
        idx = im;
        for(int om=0; om<inputs.channels(); ++om) {
            Mat field(inputs.rows,inputs.cols,CV_64F);
            extractChannel(inputs,field,om);
            
            Mat kernel(kernels.rows,kernels.cols,CV_64F);
            extractChannel(kernels,kernel,idx);
            rotate(kernel,kernel,ROTATE_180);
            
            z += conv2D(field,kernel,full);
            
            idx += kernels.channels()/inputs.channels();
        }
        conv_array.push_back(z);
    }
    
    merge(conv_array,conv);
    return conv;
}

Mat LayerConvolution::conv2D(Mat input, Mat kernel, convolution_type type) {
    Mat output,flip_kernel;
    Mat source = input;
    
    if(type == full) {
        source = Mat();
        int add_row = kernel.rows-1, add_col = kernel.cols-1;
        copyMakeBorder(input,source,(add_row+1)/2,add_row/2,(add_col+1)/2,add_col/2,BORDER_CONSTANT,Scalar(0));
    }
    
    Point anchor(kernel.cols-kernel.cols/2-1,kernel.rows-kernel.rows/2-1);
    flip(kernel,flip_kernel,-1);
    filter2D(source,output,input.depth(),flip_kernel,anchor,0,BORDER_CONSTANT);
    
    if(type == valid) {
        output = output.colRange((kernel.cols-1)/2,output.cols-kernel.cols/2).rowRange((kernel.rows-1)/2,output.rows-kernel.rows/2);
    }
    return output;
}










