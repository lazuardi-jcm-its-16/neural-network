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

#include "cnn.h"

using namespace std;
using namespace cv;

/*
 * 
 */
int main(int argc, char** argv) {
    DataPreparation data;
    
    Size size_input(28,28);
    Size size_local_field(5,5);
    int number_of_feature_maps = 20;
    
    cnn conv(size_input,size_local_field,number_of_feature_maps);
    conv.train_data(&data);
    return -1;
}

