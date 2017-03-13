/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Relu.h
 * Author: rif
 *
 * Created on March 10, 2017, 3:16 PM
 */

#ifndef RELU_H
#define RELU_H

#include <math.h> 
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

class Relu {
public:
    Relu(double z);
    Relu(const Relu& orig);
    
    double Compute();                       // sigmoid function
    static double Compute(double z);        // sigmoid function
    static Mat Compute(Mat z);        // sigmoid function
    
    virtual ~Relu();
private:
    double z;
};

#endif /* RELU_H */

