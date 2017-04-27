/*
 * Copyright (C) INFOGLOBAL TEKNOLOGI SEMESTA, PT - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential.
 */

/* 
 * File:   ActRelu.h
 * Author: RIF <arif.lazuardi@infoglobal.co.id>
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