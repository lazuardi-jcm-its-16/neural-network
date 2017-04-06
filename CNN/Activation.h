/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Activation.h
 * Author: rif
 *
 * Created on March 29, 2017, 10:12 AM
 */

#ifndef ACTIVATION_H
#define ACTIVATION_H

#include <iostream>
#include <math.h> 
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

class Activation {
public:
    virtual Mat compute(Mat z) = 0;
    Mat compute_prime(Mat z);
};

#endif /* ACTIVATION_H */

