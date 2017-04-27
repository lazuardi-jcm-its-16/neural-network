/*
 * Copyright (C) INFOGLOBAL TEKNOLOGI SEMESTA, PT - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential.
 */

/* 
 * File:   ActSigmoid.h
 * Author: RIF <arif.lazuardi@infoglobal.co.id>
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

