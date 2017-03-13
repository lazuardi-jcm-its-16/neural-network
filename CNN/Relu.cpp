/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Relu.cpp
 * Author: rif
 * 
 * Created on March 10, 2017, 3:16 PM
 */

#include "Relu.h"

Relu::Relu(double z) {
    this->z = z;
}

Relu::Relu(const Relu& orig) {
}

double Relu::Compute() {
    return (z < 0) ? 0 : z;
}

double Relu::Compute(double z) {
    return (z < 0) ? 0 : z;
}

Mat Relu::Compute(Mat z) {
    for(int x=0; x<z.rows; ++x) {
        for(int y=0; y<z.cols; ++y) {
            float zf = z.at<float>(x,y);
            z.at<float>(x,y) = (zf < 0) ? 0 : zf;
        }
    }
    return z;
}

Relu::~Relu() {
}

