/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PoolMax.h
 * Author: rif
 *
 * Created on April 4, 2017, 2:11 PM
 */

#ifndef POOLMAX_H
#define POOLMAX_H

#include "Pooling.h"

class PoolMax : public Pooling {
public:
    PoolMax(int size, int stride);
    PoolMax(const PoolMax& orig);
    virtual ~PoolMax();

    virtual Mat down_sampling(Mat x);
    virtual Mat up_sampling(Mat y);

private:

};

#endif /* POOLMAX_H */

