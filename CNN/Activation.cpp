/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Activation.cpp
 * Author: rif
 * 
 * Created on March 10, 2017, 3:16 PM
 */

#include "Activation.h"

Mat Activation::compute_prime(Mat z) {
    Mat activation(z.rows,z.cols,z.type()); 
    activation = compute(z);
    return activation.mul((1.0-activation));
}
