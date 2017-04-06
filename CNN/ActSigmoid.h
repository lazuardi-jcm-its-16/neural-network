/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ActSigmoid.h
 * Author: rif
 *
 * Created on February 27, 2017, 5:07 PM
 */

#ifndef ACTSIGMOID_H
#define ACTSIGMOID_H

#include "Activation.h"

class ActSigmoid: public Activation {
public: 
    ActSigmoid();
    ActSigmoid(const ActSigmoid& orig);
    virtual ~ActSigmoid();
    
    virtual Mat compute(Mat z);
};

#endif /* ACTSIGMOID_H */

