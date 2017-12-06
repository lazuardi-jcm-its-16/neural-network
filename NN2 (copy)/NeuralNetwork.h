/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NeuralNetwork.h
 * Author: rif
 *
 * Created on March 3, 2017, 3:30 PM
 */

#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <opencv2/core.hpp>

#include "DataPreparation.h"
using namespace cv;

#ifdef __cplusplus
extern "C" {
#endif
    
    class NeuralNetwork {
        public:
            virtual void Initialize() = 0;
            
            DataPreparation *data;
            
            int *layers;
            int length_of_layers;
            
            Mat *biases;
            Mat *weights;
            Mat *nabla_biases;
            Mat *nabla_weights;
            
            Mat *activations;
            Mat *zs;
    };


#ifdef __cplusplus
}
#endif

#endif /* NEURALNETWORK_H */

