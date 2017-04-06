/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PoolMax.cpp
 * Author: rif
 * 
 * Created on April 4, 2017, 2:11 PM
 */

#include "PoolMax.h"

PoolMax::PoolMax(int size, int stride) : Pooling() {
    this->pool_size.height = size;
    this->pool_size.width = size;
    this->stride = stride;
}

PoolMax::PoolMax(const PoolMax& orig) {
}

PoolMax::~PoolMax() {
}

Mat PoolMax::down_sampling(Mat x) {
    double min_val,max_val;
    Point min_loc,max_loc;
    vector<Mat> z_channels;
    
    Mat z(x.rows/pool_size.width, x.cols/pool_size.height, CV_32FC(x.channels()));
    for(int i=0; i<x.channels(); i++) {
        Mat o(z.rows,z.cols,CV_32F);  
        
        Mat feature(x.rows,x.cols,CV_32F);
        extractChannel(x,feature,i);
        
        for(int x=0; x<z.rows; x++) {
            for(int y=0; y<z.cols; y++) {
                Point point(y*pool_size.width,x*pool_size.height);
                Rect rect(point, pool_size);
                Mat pool_field = feature(rect);

                minMaxLoc(pool_field,&min_val,&max_val,&min_loc,&max_loc,Mat());
                o.at<float>(y,x) = max_val;
            }
        }
        
        z_channels.push_back(o);
    }
    merge(z_channels,z);
    return z;
}

Mat PoolMax::up_sampling(Mat y) {
    return y;
}




