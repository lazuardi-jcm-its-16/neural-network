/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LayerPool.h
 * Author: rif
 *
 * Created on March 24, 2017, 2:08 PM
 */

#ifndef LAYERPOOL_H
#define LAYERPOOL_H

#include "Layer.h"
#include "Pooling.h"


class LayerPool: public Layer {
public:
    LayerPool(Pooling* pool);
    LayerPool(const LayerPool& orig);
    virtual ~LayerPool();
   
    virtual void feed_forward(Mat x);
    virtual void intialization();
    
    Pooling* pool;
private:
    virtual void compute_z();
    virtual void compute_a();
};

#endif /* LAYERPOOL_H */

