/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DataPreparation.h
 * Author: rif
 *
 * Created on March 1, 2017, 11:29 AM
 */

#ifndef DATAPREPARATION_H
#define DATAPREPARATION_H

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

class DataPreparation {
public:
    DataPreparation();
    DataPreparation(const DataPreparation& orig);
    virtual ~DataPreparation();
    Mat * train_vectors;
    Mat * train_images;
    Mat * train_labels;
    Mat * test_vectors;
    Mat * test_images;
    Mat * test_labels;
    
    int number_of_train_data;
    int number_of_test_data;
private:
    char * load_file(char * pFile);
    int decode_to_int32(char* payload, int start_bit, int end_bit);
    int decode_to_int32(char* payload, int bit);
};

#endif /* DATAPREPARATION_H */

