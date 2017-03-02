/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cnn.cpp
 * Author: rif
 * 
 * Created on February 24, 2017, 3:49 PM
 */

#include "CNN.h"


CNN::CNN() {
    buffer_train_images = load_file("train-images.idx3-ubyte");
    if(decode_to_int32(buffer_train_images,0,3) == 2051) 
    {
        //int number_of_itemss = decode_to_int32(buffer_train_images,4,7);
        int number_of_items = 60000;
        int rows = decode_to_int32(buffer_train_images,8,11);
        int columns = decode_to_int32(buffer_train_images,12,15);
        
        Mat images[number_of_items];
        int idx = 16;
        for(int i=0; i<number_of_items; i++) 
        {
            Mat temp(rows,columns, CV_8UC1, Scalar::all(0));
            uchar* p = temp.ptr();
            for(int j=0; j<(rows*columns); j++) {
                p[j] = decode_to_int32(buffer_train_images,idx++);
            }
            images[i] = temp.clone();
        }
    }
    
    /*buffer_train_images_labels = this->load_file("train-labels.idx1-ubyte");
    buffer_test_images = this->load_file("t10k-images.idx3-ubyte");
    buffer_test_images_labels = this->load_file("t10k-labels.idx1-ubyte");*/
}

CNN::CNN(const CNN& orig) {
}

CNN::~CNN() {
    
}

char * CNN::load_file(char * file_name) {
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

int CNN::decode_to_int32(char* payload, int start_bit, int end_bit)
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
int CNN::decode_to_int32(char* payload, int bit)
{
    return decode_to_int32(payload,bit,bit);
}

