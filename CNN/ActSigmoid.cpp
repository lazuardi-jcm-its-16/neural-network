/*
 * Copyright (C) INFOGLOBAL TEKNOLOGI SEMESTA, PT - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential.
 */

/* 
 * File:   ActSigmoid.cpp
 * Author: RIF <arif.lazuardi@infoglobal.co.id>
 * 
 * Created on February 27, 2017, 5:07 PM
 */

#include "ActSigmoid.h"

ActSigmoid::ActSigmoid() : Activation()  {
    //this->type = activation_type.sigmoid;
}

ActSigmoid::ActSigmoid(const ActSigmoid& orig) {
}

ActSigmoid::~ActSigmoid() {
}

Mat ActSigmoid::compute(Mat z) {
    vector<Mat> a_channels;
    Mat a(z.rows, z.cols, CV_64FC(z.channels()));
    
    for(int i=0; i<z.channels(); i++) {
        Mat o(z.rows,z.cols,CV_64F);
        
        Mat feature(z.rows,z.cols,CV_64F);
        extractChannel(z,feature,i);
        
        for(int x=0; x<feature.rows; x++) {
            for(int y=0; y<feature.cols; y++) {
                o.at<double>(x,y) = 1.0 / (1.0 + exp(-feature.at<double>(x,y)));
            }
        }
        a_channels.push_back(o);
    }
    merge(a_channels,a);
    return a;
}