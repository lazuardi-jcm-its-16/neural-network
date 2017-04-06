/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ActRelu.cpp
 * Author: rif
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
    Mat a(z.rows, z.cols, CV_32FC(z.channels()));
    
    for(int i=0; i<z.channels(); i++) {
        Mat o(z.rows,z.cols,CV_32F);     
        Mat feature(z.rows,z.cols,CV_32F);
        extractChannel(z,feature,i);
        
        for(int x=0; x<feature.rows; x++) {
            for(int y=0; y<feature.cols; y++) {
                o.at<float>(y,x) = (feature.at<float>(y,x) < 0.0f) ? 0.0f : feature.at<float>(y,x);
            }
        }
        a_channels.push_back(o);
    }
    merge(a_channels,a);
    return a;
}