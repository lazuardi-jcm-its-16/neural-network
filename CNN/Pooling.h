/*
 * Copyright (C) INFOGLOBAL TEKNOLOGI SEMESTA, PT - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential.
 */

/* 
 * File:   Pooling.h
 * Author: RIF <arif.lazuardi@infoglobal.co.id>
 *
 * Created on April 4, 2017, 3:24 PM
 */

#ifndef POOLING_H
#define POOLING_H

#include <iostream>
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

class Pooling {
public:
    virtual Mat down_sampling(Mat x,Size pool_size,int stride) = 0;
    virtual Mat up_sampling(Mat y,Size pool_size,int stride) = 0;
private:
    
};


#endif /* POOLING_H */

