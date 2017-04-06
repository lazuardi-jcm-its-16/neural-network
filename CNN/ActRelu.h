/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ActRelu.h
 * Author: rif
 *
 * Created on March 10, 2017, 3:16 PM
 */

#ifndef ACTRELU_H
#define ACTRELU_H

#include "Activation.h"

class ActRelu: public Activation {
public:
    ActRelu();
    ActRelu(const ActRelu& orig);
    virtual ~ActRelu();
    
    virtual Mat compute(Mat z);
};

#endif /* ACTRELU_H */