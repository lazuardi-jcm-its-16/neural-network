/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PoolAverage.h
 * Author: rif
 *
 * Created on April 4, 2017, 2:12 PM
 */

#ifndef POOLAVERAGE_H
#define POOLAVERAGE_H

#include "Pooling.h"

class PoolAverage : public Pooling{
public:
    PoolAverage(int stride);
    PoolAverage(const PoolAverage& orig);
    virtual ~PoolAverage();

    virtual Mat down_sampling(Mat x);
    virtual Mat up_sampling(Mat y);

private:

};

#endif /* POOLAVERAGE_H */

