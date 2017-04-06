/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pooling.h
 * Author: rif
 *
 * Created on April 4, 2017, 3:24 PM
 */

#ifndef POOLING_H
#define POOLING_H

#include <iostream>
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

class Pooling {
public:
    virtual Mat down_sampling(Mat x) = 0;
    virtual Mat up_sampling(Mat y) = 0;
    
    Size pool_size;
    int stride;
private:
    
};


#endif /* POOLING_H */

