/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NNLargeWeightsBiases.h
 * Author: rif
 *
 * Created on March 3, 2017, 3:48 PM
 */

#ifndef NNLARGEWEIGHTSBIASES_H
#define NNLARGEWEIGHTSBIASES_H

#include "NeuralNetwork.h"
#include <opencv2/core.hpp>

using namespace cv;

class NNLargeWeightsBiases: public NeuralNetwork {
public:
    NNLargeWeightsBiases();
    NNLargeWeightsBiases(const NNLargeWeightsBiases& orig);
    virtual ~NNLargeWeightsBiases();
    
    virtual void Initialize();
private:

};

#endif /* NNLARGEWEIGHTSBIASES_H */

