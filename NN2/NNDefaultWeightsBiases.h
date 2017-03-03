/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NNDefaultWeightsBiases.h
 * Author: rif
 *
 * Created on March 3, 2017, 3:37 PM
 */

#ifndef NNDEFAULTWEIGHTSBIASES_H
#define NNDEFAULTWEIGHTSBIASES_H

#include "NeuralNetwork.h"
#include <opencv2/core.hpp>

using namespace cv;

class NNDefaultWeightsBiases: public NeuralNetwork {
public:
    NNDefaultWeightsBiases();
    NNDefaultWeightsBiases(const NNDefaultWeightsBiases& orig);
    virtual ~NNDefaultWeightsBiases();
    
    virtual void Initialize();
private:

};

#endif /* NNDEFAULTWEIGHTSBIASES_H */

