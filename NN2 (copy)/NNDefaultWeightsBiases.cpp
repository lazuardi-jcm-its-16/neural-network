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
    biases = new Mat[length_of_layers-1];
    weights = new Mat[length_of_layers-1];
    nabla_biases = new Mat[length_of_layers-1];
    nabla_weights = new Mat[length_of_layers-1];
    activations = new Mat[length_of_layers];
    zs = new Mat[length_of_layers-1];
    
    for(int i=1; i<length_of_layers; ++i) {
        nabla_biases[i-1] = Mat::zeros(layers[i],1, CV_64FC1);
        nabla_weights[i-1] = Mat::zeros(layers[i],layers[i-1], CV_64FC1);
        
        biases[i-1] = nabla_biases[i-1].clone();
        weights[i-1] = nabla_weights[i-1].clone(); 
        randn(biases[i-1],0,1);
        randn(weights[i-1],0,1);
        
        Mat weight_sqrt = weights[i-1].clone();
        sqrt(weights[i-1],weight_sqrt);
        divide(weights[i-1],weight_sqrt,weights[i-1],1,-1);
    }
    
    std::cout << weights[0] << std::endl;
}