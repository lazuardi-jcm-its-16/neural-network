/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CNN.cpp
 * Author: rif
 * 
 * Created on April 6, 2017, 4:12 PM
 */

#include "CNN.h"

CNN::CNN() {
}

CNN::CNN(const CNN& orig) {
}

CNN::~CNN() {
}

void CNN::set_data(DataPreparation* data) {
    this->data = data;
}

void CNN::push_layer(Layer* layer) {
    layers.push_back(layer);
}

void CNN::initialization() {
    number_of_layers = layers.size();
    
    for(int i=0; i<number_of_layers; i++) {
        switch(layers[i]->type) {
            case convolution: {
                layers[i]->intialization();
                break;
            }
            case pooling: {
                break;
            }  
            case fully_connected: {
                break;
            }
        }
    } 
}




