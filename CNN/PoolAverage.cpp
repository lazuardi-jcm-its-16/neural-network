/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PoolAverage.cpp
 * Author: rif
 * 
 * Created on April 4, 2017, 2:12 PM
 */

#include "PoolAverage.h"

PoolAverage::PoolAverage(int stride) : Pooling() {
    this->stride = stride;
}

PoolAverage::PoolAverage(const PoolAverage& orig) {
}

PoolAverage::~PoolAverage() {
}

Mat PoolAverage::down_sampling(Mat x) {
    
    return x;
}

Mat PoolAverage::up_sampling(Mat y) {
    return y;
}




