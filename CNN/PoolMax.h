/*
 * Copyright (C) INFOGLOBAL TEKNOLOGI SEMESTA, PT - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential.
 */

/* 
 * File:   PoolMax.h
 * Author: RIF <arif.lazuardi@infoglobal.co.id>
 *
 * Created on April 4, 2017, 2:11 PM
 */

#ifndef POOLMAX_H
#define POOLMAX_H

#include "Pooling.h"

class PoolMax : public Pooling {
public:
    PoolMax();
    PoolMax(const PoolMax& orig);
    virtual ~PoolMax();

    virtual Mat down_sampling(Mat x,Size pool_size,int stride);
    virtual Mat up_sampling(Mat y,Size pool_size,int stride);

private:

};

#endif /* POOLMAX_H */

