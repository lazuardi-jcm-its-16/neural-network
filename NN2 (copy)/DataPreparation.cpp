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
    
    number_of_train_data = 18;
    train_vectors = new Mat[number_of_train_data];
    train_images = new Mat[number_of_train_data];
    train_labels = new Mat[number_of_train_data];
    
    std::string::size_type sz;
    std::ifstream file_train("fitur_train.csv");
    
    int i = 0;
    CSVRow row_train;
    while(file_train >> row_train) {
        Mat temp_vector(16,1, CV_64FC1, Scalar::all(0));
        for(int j=0; j<16; j++) {
            temp_vector.at<double>(j,0) = atof(row_train[j].c_str());
        }
        
        Mat temp_label(6,1, CV_8UC1, Scalar::all(0));
        int idx = atoi(row_train[16].c_str());
        temp_label.at<uchar>((idx-1),0) = 1;
        
        train_vectors[i] = temp_vector.clone();
        train_images[i] = temp_vector.reshape(1,4);
        train_labels[i] = temp_label.clone();
        
        i++;
    }
    
    
    
    number_of_test_data = 9;
    test_vectors = new Mat[number_of_test_data];
    test_images = new Mat[number_of_test_data];
    test_labels = new Mat[number_of_test_data];
    
    std::ifstream file_test("fitur_test.csv");
    i = 0;
    CSVRow row_test;
    while(file_test >> row_test) {
        Mat temp_vector(16,1, CV_64FC1, Scalar::all(0));
        for(int j=0; j<16; j++) {
            
            temp_vector.at<double>(j,0) = atof(row_test[j].c_str());
        }
        
        Mat temp_label(6,1, CV_8UC1, Scalar::all(0));
        int idx = atoi(row_test[16].c_str());
        temp_label.at<uchar>((idx-1),0) = 1;
        
        test_vectors[i] = temp_vector.clone();
        test_images[i] = temp_vector.reshape(1,4);
        test_labels[i] = temp_label.clone();
        
        i++;
        
    }
    
    
    /*
    char * buffer_train_images = load_file("train-images.idx3-ubyte");
    if(decode_to_int32(buffer_train_images,0,3) == 2051) {
        //int number_of_items = decode_to_int32(buffer_train_images,4,7);
        //number_of_train_data = 60000;
        number_of_train_data = 250;
        int rows = decode_to_int32(buffer_train_images,8,11);
        int columns = decode_to_int32(buffer_train_images,12,15);
        
        train_vectors = new Mat[number_of_train_data];
        train_images = new Mat[number_of_train_data];
        int idx = 16;
        for(int i=0; i<number_of_train_data; i++) {
            Mat temp_vector(rows*columns,1, CV_8UC1, Scalar::all(0));
            Mat temp_images(rows,columns, CV_8UC1, Scalar::all(0));
            uchar* vec = temp_vector.ptr();
            uchar* img = temp_images.ptr();
            for(int j=0; j<(rows*columns); j++) {
                int a = decode_to_int32(buffer_train_images,idx++);
                vec[j] = a;
                img[j] = a;
            }
            train_vectors[i] = temp_vector.clone();
            train_images[i] = temp_images.clone();
        }
    }
    
            
    char * buffer_train_images_labels = load_file("train-labels.idx1-ubyte");
    if(decode_to_int32(buffer_train_images_labels,0,3) == 2049) {
        //number_of_train_data = 60000;
        number_of_train_data = 250;
        train_labels = new Mat[number_of_train_data];
        int idx = 8;
        for(int i=0; i<number_of_train_data; i++) {
            Mat temp(10,1, CV_8UC1, Scalar::all(0));
            uchar* p = temp.ptr();
            p[decode_to_int32(buffer_train_images_labels,idx++)] = 1;
            train_labels[i] = temp.clone();
        }
    }
    
    char * buffer_test_images = load_file("t10k-images.idx3-ubyte");
    if(decode_to_int32(buffer_test_images,0,3) == 2051) {
        //int number_of_items = decode_to_int32(buffer_test_images,4,7);
        //number_of_test_data = 10000;
        number_of_test_data = 10;
        int rows = decode_to_int32(buffer_test_images,8,11);
        int columns = decode_to_int32(buffer_test_images,12,15);
        
        test_vectors = new Mat[number_of_test_data];
        test_images = new Mat[number_of_test_data];
        int idx = 16;
        for(int i=0; i<number_of_test_data; i++) {
            Mat temp_vector(rows*columns,1, CV_8UC1, Scalar::all(0));
            Mat temp_images(rows,columns, CV_8UC1, Scalar::all(0));
            uchar* vec = temp_vector.ptr();
            uchar* img = temp_images.ptr();
            for(int j=0; j<(rows*columns); j++) {
                int a = decode_to_int32(buffer_test_images,idx++);
                vec[j] = a;
                img[j] = a;
            }
            test_vectors[i] = temp_vector.clone();
            test_images[i] = temp_images.clone();
        }
    }
    
    char * buffer_test_images_labels = load_file("t10k-labels.idx1-ubyte");
    if(decode_to_int32(buffer_test_images_labels,0,3) == 2049) {
        //number_of_test_data = 10000;
        number_of_test_data = 10;
        test_labels = new Mat[number_of_test_data];
        int idx = 8;
        for(int i=0; i<number_of_test_data; i++) {
            Mat temp(1,1, CV_8UC1, Scalar::all(0));
            uchar* p = temp.ptr();
            p[0] = decode_to_int32(buffer_test_images_labels,idx++);
            test_labels[i] = temp.clone();
        }
    }
    
    cout << test_labels[0] << endl;
    imshow("tes", test_images[0]);
    waitKey(1);*/
    
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

