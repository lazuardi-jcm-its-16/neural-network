/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DNN.h
 * Author: rif
 *
 * Created on March 8, 2017, 5:11 PM
 */

#ifndef DNN_H
#define DNN_H

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/dnn/dnn.hpp>
#include <opencv2/dnn/all_layers.hpp>

class DNN {
public:
    DNN();
    DNN(const DNN& orig);
    virtual ~DNN();
private:

};

#endif /* DNN_H */

