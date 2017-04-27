/*
 * Copyright (C) INFOGLOBAL TEKNOLOGI SEMESTA, PT - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential.
 */

/* 
 * File:   ActRelu.cpp
 * Author: RIF <arif.lazuardi@infoglobal.co.id>
 * 
 * Created on March 10, 2017, 3:16 PM
 */

#include "ActRelu.h"

ActRelu::ActRelu() : Activation()  {
    
}

ActRelu::ActRelu(const ActRelu& orig) {
}

ActRelu::~ActRelu() {
}

Mat ActRelu::compute(Mat z){
    vector<Mat> a_channels;
    Mat a(z.rows, z.cols, CV_64FC(z.channels()));
    
    for(int i=0; i<z.channels(); i++) {
        Mat o(z.rows,z.cols,CV_64F);     
        Mat feature(z.rows,z.cols,CV_64F);
        extractChannel(z,feature,i);
        
        for(int x=0; x<feature.rows; x++) {
            for(int y=0; y<feature.cols; y++) {
                o.at<double>(y,x) = (feature.at<double>(y,x) < 0.0) ? 0.0 : feature.at<double>(y,x);
            }
        }
        a_channels.push_back(o);
    }
    merge(a_channels,a);
    return a;
}
