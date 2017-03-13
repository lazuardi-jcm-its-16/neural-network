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

#include "CNN.h"

using namespace std;
using namespace cv;

/*
 * 
 */
int main(int argc, char** argv) {
    DataPreparation data;
    
    Size size_input(28,28);
    Size size_convolution(5,5);
    Size size_pooling(2,2);
    Size size_output(1,10);
    int number_of_feature_maps = 20;
    
    CNN cnn(size_input,size_convolution,size_pooling,size_output,number_of_feature_maps);
    cnn.train_data(&data,30);
    
    /*
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
    return -1;
}

