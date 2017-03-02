/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cnn.h
 * Author: rif
 *
 * Created on February 24, 2017, 3:49 PM
 */

#ifndef CNN_H
#define CNN_H

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

class CNN {
public:
    CNN();
    CNN(const CNN& orig);
    virtual ~CNN();
private:
    char * buffer_train_images;
    char * buffer_train_images_labels;
    char * buffer_test_images;
    char * buffer_test_images_labels;
    
    char * load_file(char * pFile);
    int decode_to_int32(char* payload, int start_bit, int end_bit);
    int decode_to_int32(char* payload, int bit);
};

#endif /* CNN_H */

