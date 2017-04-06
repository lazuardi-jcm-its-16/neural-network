/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LayerFC.cpp
 * Author: rif
 * 
 * Created on March 24, 2017, 2:10 PM
 */

#include "LayerFC.h"

LayerFC::LayerFC(Activation* act) : Layer() {
    this->type = fully_connected;
    this->activation = act;
}

LayerFC::LayerFC(const LayerFC& orig) {
}

LayerFC::~LayerFC() {
}

void LayerFC::intialization(int number_of_neuron_input, int number_of_neuron_output) {
    this->number_of_neuron_input = number_of_neuron_input;
    this->number_of_neuron_output = number_of_neuron_output;
}

void LayerFC::intialization() {
    weights.create(number_of_neuron_output,number_of_neuron_input, CV_32F);
    randn(weights,0,1);
    
    biases.create(number_of_neuron_output,1, CV_32F);
    randn(biases,0,1);
}

void LayerFC::feed_forward(Mat x) {
    this->x = x;
    
    if(this->x.rows >1) {
        x_as_vector = tranform_to_vector(this->x);
    }
    else {
        x_as_vector = this->x.clone();
    }
    
    compute_z();
    compute_a();
}

void LayerFC::compute_z() {
    z = weights * x_as_vector + biases;
}

void LayerFC::compute_a() {
    a = activation->compute(z);
}

Mat LayerFC::tranform_to_vector(Mat x) {
    int length = x.rows*x.cols*x.channels();
    vector<float> pool(length);
    if(x.isContinuous()) {
        pool.assign((float*)x.datastart, (float*)x.dataend);
    }
    
    Mat pool_vector(length,1,CV_32F);
    memcpy(pool_vector.data, pool.data(), pool.size()*sizeof(float));
    return pool_vector;
}




