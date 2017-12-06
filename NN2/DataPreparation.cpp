/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DataPreparation.cpp
 * Author: rif
 * 
 * Created on March 1, 2017, 11:29 AM
 */

#include <string.h>
#include "DataPreparation.h"
#include "CSVIterator.h"

std::istream& operator>>(std::istream& str, CSVRow& data)
{
    data.readNextRow(str);
    return str;
} 


DataPreparation::DataPreparation() {
    std::ifstream file_train("fitur_train.csv");
    number_of_train_data = 12;
    CSVRow row_train;
    while(file_train >> row_train) {
        Mat temp_vector(16,1, CV_64FC1, Scalar::all(0));
        for(int j=0; j<16; j++) {
            temp_vector.at<double>(j,0) = atof(row_train[j].c_str());
        }
        
        Mat temp_label(6,1, CV_8UC1, Scalar::all(0));
        int idx = atoi(row_train[16].c_str());
        temp_label.at<uchar>((idx-1),0) = 1;
        
        train_vectors.push_back(temp_vector);
        train_labels.push_back(temp_label);
    }
    
    std::ifstream file_test("fitur_test.csv");
    number_of_test_data = 9;
    CSVRow row_test;
    while(file_test >> row_test) {
        Mat temp_vector(16,1, CV_64FC1, Scalar::all(0));
        for(int j=0; j<16; j++) {
            temp_vector.at<double>(j,0) = atof(row_test[j].c_str());
        }
        
        Mat temp_label(6,1, CV_8UC1, Scalar::all(0));
        int idx = atoi(row_test[16].c_str());
        temp_label.at<uchar>((idx-1),0) = 1;
        
        test_vectors.push_back(temp_vector);
        test_labels.push_back(temp_label);
    }
    
    
}

DataPreparation::DataPreparation(const DataPreparation& orig) {
}

DataPreparation::~DataPreparation() {
}

char * DataPreparation::load_file(char * file_name) {
    FILE * pFile;
    long lSize;
    char * buffer;
    size_t result;
    
    pFile = fopen(file_name,"rb");
    if (pFile==NULL) 
    {
        fputs("File error",stderr); 
    }
    
    // obtain file size:
    fseek (pFile , 0 , SEEK_END);
    lSize = ftell (pFile);
    rewind (pFile);
    
    // allocate memory to contain the whole file:
    buffer = (char*) malloc (sizeof(char)*lSize);
    if (buffer == NULL) 
    {
        fputs("Memory error",stderr);
    }
    
    // copy the file into the buffer:
    result = fread(buffer,1,lSize,pFile);
    if (result != lSize) 
    {
        fputs("Reading error",stderr); 
    }

    fclose (pFile);
    //free (buffer);
    return buffer;
}

int DataPreparation::decode_to_int32(char* payload, int start_bit, int end_bit)
{
    unsigned int val;
    int bit = (end_bit-start_bit)*8;

    for(int i=start_bit; i<=start_bit+(end_bit-start_bit); i++) 
    {
        if(i == start_bit) 
        {
            val = payload[i] << bit;
        }
        else if(i == end_bit)
        {
            val |= payload[i];
        }
        else 
        {
            val |= payload[i] << bit;
        }
        bit -= 8;
    }
    
    return val;
}
int DataPreparation::decode_to_int32(char* payload, int bit)
{
    return decode_to_int32(payload,bit,bit);
}

