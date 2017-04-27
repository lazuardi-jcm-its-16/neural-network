/*
 * Copyright (C) INFOGLOBAL TEKNOLOGI SEMESTA, PT - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential.
 */

/* 
 * File:   Activation.h
 * Author: RIF <arif.lazuardi@infoglobal.co.id>
 *
 * Created on March 29, 2017, 10:12 AM
 */

#ifndef ACTIVATION_H
#define ACTIVATION_H

#include <iostream>
#include <math.h> 
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

class Activation {
public:
    virtual Mat compute(Mat z) = 0;
    Mat compute_prime(Mat a);
};

#endif /* ACTIVATION_H */

