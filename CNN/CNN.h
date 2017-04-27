/*
 * Copyright (C) INFOGLOBAL TEKNOLOGI SEMESTA, PT - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential.
 */

/* 
 * File:   CNN.h
 * Author: RIF <arif.lazuardi@infoglobal.co.id>
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
    double alpha;
    
    void feed_forward();
    void back_pass();
    void apply_grads();
};

#endif /* CNN_H */

