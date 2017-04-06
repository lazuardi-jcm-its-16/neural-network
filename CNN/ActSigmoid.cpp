/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ActSigmoid.cpp
 * Author: rif
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
    Mat a(z.rows, z.cols, CV_32FC(z.channels()));
    
    for(int i=0; i<z.channels(); i++) {
        Mat o(z.rows,z.cols,CV_32F);
        
        Mat feature(z.rows,z.cols,CV_32F);
        extractChannel(z,feature,i);
        
        for(int x=0; x<feature.rows; x++) {
            for(int y=0; y<feature.cols; y++) {
                o.at<float>(y,x) = 1.0 / 1.0 + exp(-feature.at<float>(y,x));
            }
        }
        a_channels.push_back(o);
    }
    merge(a_channels,a);
    return a;
}