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
    return 1.0 / 1.0 + exp(-z);
}

double Sigmoid::Compute(double z) {
    return 1.0 / 1.0 + exp(-z);
}

Mat Sigmoid::Compute(Mat z) {
    Mat y = z.clone();
    uchar* zp = z.ptr();
    uchar* yp = y.ptr();
    for(int i=0; i<z.rows*z.cols; ++i) {
        yp[i] = 1.0 / 1.0 + exp(-zp[i]);
    }
    return y;
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

 
Sigmoid::~Sigmoid() {
}

