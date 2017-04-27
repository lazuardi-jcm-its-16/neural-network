/*
 * Copyright (C) INFOGLOBAL TEKNOLOGI SEMESTA, PT - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential.
 */

/* 
 * File:   PoolMax.cpp
 * Author: RIF <arif.lazuardi@infoglobal.co.id>
 * 
 * Created on April 4, 2017, 2:11 PM
 */

#include "PoolMax.h"

PoolMax::PoolMax() : Pooling() {
}

PoolMax::PoolMax(const PoolMax& orig) {
}

PoolMax::~PoolMax() {
}

Mat PoolMax::down_sampling(Mat x,Size pool_size,int stride) {
    double min_val,max_val;
    Point min_loc,max_loc;
    vector<Mat> z_channels;
    
    Mat z(x.rows/pool_size.width, x.cols/pool_size.height, CV_64FC(x.channels()));
    for(int i=0; i<x.channels(); i++) {
        Mat o(z.rows,z.cols,CV_64F);  
        
        Mat feature(x.rows,x.cols,CV_64F);
        extractChannel(x,feature,i);
        
        for(int x=0; x<z.rows; x++) {
            for(int y=0; y<z.cols; y++) {
                Point point(y*pool_size.width,x*pool_size.height);
                Rect rect(point, pool_size);
                Mat pool_field = feature(rect);

                minMaxLoc(pool_field,&min_val,&max_val,&min_loc,&max_loc,Mat());
                o.at<double>(x,y) = max_val;
            }
        }
        
        z_channels.push_back(o);
    }
    merge(z_channels,z);
    return z;
}

Mat PoolMax::up_sampling(Mat y,Size pool_size,int stride) {
    Mat x;
    x.zeros(y.rows*pool_size.height,y.cols*pool_size.width,y.channels());
    vector<Mat> x_channels;
    for(int i=0; i<y.channels(); i++) {
        Mat o(y.rows*pool_size.height,y.cols*pool_size.width,CV_64F);  
        
        Mat feature(y.rows,y.cols,CV_64F);
        extractChannel(y,feature,i);
        
        for(int i=0; i<y.rows; i++) {
            int ii = i*2+1;
            for(int j=0; j<y.cols; j++) {
                int jj=j*2+1;
                o.at<double>(jj,ii) = y.at<double>(j,i);
            }
        }
        
        x_channels.push_back(o);
    }
    merge(x_channels,x);
    return x;
}




