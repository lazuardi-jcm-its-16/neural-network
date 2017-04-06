/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rif
 *
 * Created on February 27, 2017, 5:05 PM
 */

#include <iostream>
#include <opencv2/core.hpp>

#include "CNN2.h"
#include "Activation.h"
#include "ActRelu.h"
#include "LayerConvolution.h"
#include "PoolMax.h"
#include "LayerPool.h"
#include "LayerFC.h"
#include "CNN.h"

using namespace std;
using namespace cv;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Mat input;
    DataPreparation data;
    data.train_images[0].convertTo(input,CV_32F);
    input = input / 255.0f;
    
    
    // LAYERS
    ActRelu activation;
    LayerConvolution convolution(3,5,1,&activation);
    
    PoolMax pool(2,2);
    LayerPool pooling(&pool);
      
    LayerFC fc(&activation);
    
    CNN cnn;
    cnn.set_data(&data);
    
    cnn.push_layer(&convolution);
    cnn.push_layer(&pooling);
    cnn.push_layer(&fc);
    
    
    
    
    
    //convolution.feed_forward(input);
    //pooling.feed_forward(convolution.a);
    //fc.intialization(pooling.a.rows*pooling.a.cols*pooling.a.channels(),10)
    //fc.feed_forward(pooling.a);
    
    /*
    Mat feature(pooling.z.rows,pooling.z.cols,CV_32F);
    extractChannel(pooling.z,feature,0);  
    cout << feature << endl;
    extractChannel(pooling.z,feature,1);  
    cout << feature << endl;
    extractChannel(pooling.z,feature,2);  
    cout << feature << endl;
    
    imshow("tes", data.train_images[0]);
    waitKey();*/
    
    /*
    Mat I = Mat::ones(28, 28, CV_32F);
    Mat k = Mat::eye(5, 5, CV_32F) * 3;
    Mat O = Mat::zeros(28, 28, CV_32F);
    Point p;
    p.x = 0;
    p.y = 0;
    
    filter2D(I,O,CV_32F,k,p,0.0,BORDER_ISOLATED);
    Mat b = O.colRange(0, O.cols - 4).rowRange(0, O.rows - 4).clone();
    
    cout << I << endl;
    cout << k << endl;
    cout << O << endl;
    cout << b << endl;
    
    
    DataPreparation data;
    
    Size size_input(28,28);
    Size size_convolution(5,5);
    Size size_pooling(2,2);
    Size size_output(1,10);
    int number_of_feature_maps = 20;
    
    CNN cnn(size_input,size_convolution,size_pooling,size_output,number_of_feature_maps);
    cnn.train_data(&data,30);
    
    
    Mat tes(10,10,CV_32FC1);
    randn(tes,0,1);
    
    Size size_of_pool(2,2);
    Point point(1,0);
    Rect rect(point,size_of_pool);
    Mat local_field = tes(rect);
    
    cout << tes << endl;
    cout << endl << endl;
    cout << local_field << endl;
    cout << endl << endl;
    cout << sum(tes).val[0] << endl;*/
    return 0;
}

