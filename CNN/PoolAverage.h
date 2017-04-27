/*
 * Copyright (C) INFOGLOBAL TEKNOLOGI SEMESTA, PT - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential.
 */

/* 
 * File:   PoolAverage.h
 * Author: RIF <arif.lazuardi@infoglobal.co.id>
 *
 * Created on April 4, 2017, 2:12 PM
 */

#ifndef POOLAVERAGE_H
#define POOLAVERAGE_H

#include "Pooling.h"

class PoolAverage : public Pooling{
public:
    PoolAverage();
    PoolAverage(const PoolAverage& orig);
    virtual ~PoolAverage();

    virtual Mat down_sampling(Mat x,Size pool_size,int stride);
    virtual Mat up_sampling(Mat y,Size pool_size,int stride);

private:

};

#endif /* POOLAVERAGE_H */

