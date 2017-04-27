/*
 * Copyright (C) INFOGLOBAL TEKNOLOGI SEMESTA, PT - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential.
 */

/* 
 * File:   Activation.cpp
 * Author: RIF <arif.lazuardi@infoglobal.co.id>
 * 
 * Created on March 10, 2017, 3:16 PM
 */

#include "Activation.h"

Mat Activation::compute_prime(Mat a) {
    Mat b(a.rows,a.cols,a.channels());
    subtract(1.0,a, b);
    return a.mul(b);
}
