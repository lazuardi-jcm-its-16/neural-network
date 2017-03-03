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
#include <random>
#include "NN.h"
#include "DataPreparation.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    /*int Int[1];
    short Short[1];
    double Double[1];
    float Float[1];
    long Long[1];
    cout << sizeof(Int) << endl;
    cout << sizeof(Short) << endl;
    cout << sizeof(Double) << endl;
    cout << sizeof(Float) << endl;
    cout << sizeof(Long) << endl;
    
    int layers[3] = {8,3,1};
    int * a = &layers[0];
    cout << sizeof(layers)/sizeof(int) << endl;
    cout << a << endl;
    cout << a+1 << endl;
    cout << a+2 << endl;
    cout << a[0] << endl;
    cout << a[1] << endl;
    cout << a[2] << endl;
    
    a[3] = 10;
    cout << a[3] << endl;
    cout << layers[3] << endl;
    NN nn(&layers);
    
    default_random_engine generator;
    normal_distribution<double> distribution(0.0,1.0);
    cout << distribution(generator) << endl;
    return 0;
   
    int layers[3] = {784,30,10};
    NN nn(&layers[0],sizeof(layers)/sizeof(int));
    
    nn.sgd(&data,30,10,3.0);*/
    
    
    
    /*
    DataPreparation data;
    cout << "Jumlah data training: " << data.number_of_train_data << endl;
    cout << "Jumlah data testing: " << data.number_of_test_data << endl;
    
    cout << data.train_images[0].size.p[0] << "x" << data.test_images[0].size.p[1] << endl;
    //cout << data.train_images[0] << endl;
    cout << data.train_vectors[0].size.p[0] << "x" << data.test_vectors[0].size.p[1] << endl;
    //cout << data.train_vectors[0] << endl;
    cout << data.train_labels[0] << endl;
    
    cout << data.test_images[0].size.p[0] << "x" << data.test_images[0].size.p[1] << endl;
    //cout << data.test_images[0] << endl;
    cout << data.test_vectors[0].size.p[0] << "x" << data.test_vectors[0].size.p[1] << endl;
    //cout << data.test_vectors[0] << endl;
    cout << data.test_labels[0] << endl;*/
    
    DataPreparation data;
    int layers[3] = {784,30,10};
    NN nn(&layers[0],sizeof(layers)/sizeof(int));
    nn.sgd(&data,20,10,3.0);
    
    //cout << nn.length_of_layers << endl;
    //cout << nn.layers[0] << " " << nn.layers[1] << " " << nn.layers[2] << endl;
    //cout << nn.biases[0] << endl;
    //cout << "biases[0], size: " << nn.biases[0].size.p[0] << "x" << nn.biases[0].size.p[1] << endl;
}

