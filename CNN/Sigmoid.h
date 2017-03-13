/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sigmoid.h
 * Author: rif
 *
 * Created on February 27, 2017, 5:07 PM
 */

#ifndef SIGMOID_H
#define SIGMOID_H

#include <iostream>
#include <math.h> 
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

class Sigmoid {
public:
    Sigmoid(double z);
    Sigmoid(const Sigmoid& orig);
    
    double Compute();                       // sigmoid function
    static double Compute(double z);        // sigmoid function
    static Mat Compute(Mat z);        // sigmoid function
    
    double ComputePrime();                  // derivative of sigmoid function 
    static double ComputePrime(double z);   // derivative of sigmoid function
    static Mat ComputePrime(Mat z);   // derivative of sigmoid function
    
    virtual ~Sigmoid();
private:
    double z;
    double activation(double z);
    double activation();
    
};

#endif /* SIGMOID_H */

