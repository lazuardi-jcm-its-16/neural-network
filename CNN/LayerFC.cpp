/*
 * Copyright (C) INFOGLOBAL TEKNOLOGI SEMESTA, PT - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential.
 */

/* 
 * File:   LayerFC.cpp
 * Author: RIF <arif.lazuardi@infoglobal.co.id>
 * 
 * Created on March 24, 2017, 2:10 PM
 */

#include "LayerFC.h"
#include "LayerPool.h"

LayerFC::LayerFC(int neuron_size, Activation* act) : Layer() {
    this->type = fully_connected;
    this->number_of_neuron_output = neuron_size;
    this->activation = act;
}

LayerFC::LayerFC(const LayerFC& orig) {
}

LayerFC::~LayerFC() {
}

void LayerFC::intialization(Size input_size, int input_type, Size output_size, int output_type) {
    number_of_neuron_input = input_size.height;
    number_of_neuron_output = output_size.height;
    x_as_vector.create(input_size,input_type);
    z.create(output_size,output_type);
    a.create(output_size,output_type);
    
    weights.create(output_size.height,input_size.height, CV_64F);
    randn(weights,0,1);
    weights = (weights - 0.5)*2.0*sqrt(6.0/(number_of_neuron_input+number_of_neuron_output));
    
    biases = Mat::zeros(output_size,CV_64F);
}

void LayerFC::set_weights(Mat weights) {
    this->weights = weights;
}

void LayerFC::set_biases(Mat biases) {
    this->biases = biases;
}

void LayerFC::feed_forward(Mat x) {
    this->x = x;
    
    if(x.cols >1) {
        x_as_vector = transform_to_vector(x);
    }
    else {
        x_as_vector = x;
    }
    
    compute_z();
    compute_a();
}

void LayerFC::compute_z() {
    z = weights * x_as_vector + biases;
}

void LayerFC::compute_a() {
    a = activation->compute(z);
    cout << a << endl;
}


void LayerFC::back_pass(Mat y) {
    e = a - y;
    compute_delta();
    compute_gradient();
}

void LayerFC::compute_delta() {
    od = e.mul(activation->compute_prime(a));
    delta =  weights.t() * od;
}

void LayerFC::compute_gradient() {
    weights_update = od * x_as_vector.t();
    biases_update = od;
}

void LayerFC::apply_gradient(double alpha) {
    weights = weights - (weights_update*alpha);
    biases = biases - (biases_update*alpha);
}


Mat LayerFC::transform_to_vector(Mat x) {
    int length = x.rows*x.cols;
    vector<double> pool(length);
    
    Mat pool_vector(length*x.channels(),1,CV_64F);
    uchar* start = pool_vector.data;
    for(int i=0; i<x.channels(); ++i) {
        Mat item(x.rows,x.cols,CV_64F);
        extractChannel(x,item,i);
        
        //item = item.t();
        pool = item.reshape(1,1);
        
        memcpy(start, pool.data(), pool.size()*sizeof(double));
        start += pool.size()*sizeof(double);
    }
    
    return pool_vector;
}

Mat LayerFC::transform_to_image() {
    return transform_to_image(x.rows,x.cols,x.channels(),delta);
}

Mat LayerFC::transform_to_image(int row, int col, int channel, Mat x) {
    Mat im(row,col,CV_64FC(channel));    
    vector<Mat> im_array;
    int size = x.rows / im.channels();
    for(int i=0; i<im.channels(); i++) {
        Mat temp_1(size,1,CV_64F);
        x.rowRange(i*size,i*size+size).copyTo(temp_1);
        //im_array.push_back(temp_1.reshape(1,im.rows).t());
        im_array.push_back(temp_1.reshape(1,im.rows));
    }
    merge(im_array,im);
    return im;
}




