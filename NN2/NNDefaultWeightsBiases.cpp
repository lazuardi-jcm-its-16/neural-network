/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NNDefaultWeightsBiases.cpp
 * Author: rif
 * 
 * Created on March 3, 2017, 3:37 PM
 */

#include "NNDefaultWeightsBiases.h"

NNDefaultWeightsBiases::NNDefaultWeightsBiases() {
}

NNDefaultWeightsBiases::NNDefaultWeightsBiases(const NNDefaultWeightsBiases& orig) {
}

NNDefaultWeightsBiases::~NNDefaultWeightsBiases() {
}

void NNDefaultWeightsBiases::Initialize() {
    biases.reserve(length_of_layers-1);
    weights.reserve(length_of_layers-1);
    nabla_biases.reserve(length_of_layers-1);
    nabla_weights.reserve(length_of_layers-1);
    zs.reserve(length_of_layers-1);
    activations.reserve(length_of_layers);
    
    Mat zeros = Mat::zeros(layers[0],1, CV_64FC1);
    activations.push_back(zeros);
    
    for(int i=1; i<length_of_layers; ++i) {
        Mat zeros_activations = Mat::zeros(layers[i],1, CV_64FC1);
        Mat zeros_zs = Mat::zeros(layers[i],1, CV_64FC1);
        Mat zeros_biases = Mat::zeros(layers[i],1, CV_64FC1);
        Mat zeros_weights = Mat::zeros(layers[i],layers[i-1], CV_64FC1);
        
        activations.push_back(zeros_activations);
        zs.push_back(zeros_zs);
        nabla_biases.push_back(zeros_biases);
        nabla_weights.push_back(zeros_weights);
        biases.push_back(zeros_biases);
        weights.push_back(zeros_weights);
        
        randn(biases.at(i-1),0,1);
        randn(weights.at(i-1),0,1);
        
        
        Mat weight_sqrt = weights.at(i-1).clone();
        sqrt(weights.at(i-1),weight_sqrt);
        divide(weights.at(i-1),weight_sqrt,weights.at(i-1),1,-1);
    }
}
