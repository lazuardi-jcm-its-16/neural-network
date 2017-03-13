/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sigmoid.cpp
 * Author: rif
 * 
 * Created on February 27, 2017, 5:07 PM
 */

#include "Sigmoid.h"

Sigmoid::Sigmoid(double z) {
    this->z = z;
}

Sigmoid::Sigmoid(const Sigmoid& orig) {
}

double Sigmoid::Compute() {
    return activation();
}

double Sigmoid::Compute(double z) {
    return activation(z);
}

Mat Sigmoid::Compute(Mat z) {
    for(int x=0; x<z.rows; ++x) {
        for(int y=0; y<z.cols; ++y) {
            z.at<float>(x,y) = activation(z.at<float>(x,y));
        }
    }
    return z;
}

double Sigmoid::ComputePrime() {
    return Compute() * (1.0-Compute());
}

double Sigmoid::ComputePrime(double z) {
    return Compute(z) * (1.0-Compute(z));
}

Mat Sigmoid::ComputePrime(Mat z) {
    return Compute(z).mul((1.0-Compute(z)));
}

double Sigmoid::activation(double z) {
    return 1.0 / (1.0 + exp(-z));
}

double Sigmoid::activation() {
    activation(z);
}


 
Sigmoid::~Sigmoid() {
}

