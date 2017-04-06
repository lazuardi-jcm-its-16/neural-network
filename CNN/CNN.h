/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CNN.h
 * Author: rif
 *
 * Created on April 6, 2017, 4:12 PM
 */

#ifndef CNN_H
#define CNN_H

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

#include "DataPreparation.h"
#include "Layer.h"

using namespace std;
using namespace cv;

class CNN {
public:
    CNN();
    CNN(const CNN& orig);
    virtual ~CNN();
    
    void set_data(DataPreparation* data);
    void push_layer(Layer* layer);
    void initialization();
    
    void train();
private:
    DataPreparation* data;
    vector<Layer*> layers;
    int number_of_layers;
};

#endif /* CNN_H */

