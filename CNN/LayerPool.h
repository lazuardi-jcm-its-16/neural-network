/*
 * Copyright (C) INFOGLOBAL TEKNOLOGI SEMESTA, PT - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential.
 */

/* 
 * File:   LayerPool.h
 * Author: RIF <arif.lazuardi@infoglobal.co.id>
 *
 * Created on March 24, 2017, 2:08 PM
 */

#ifndef LAYERPOOL_H
#define LAYERPOOL_H

#include "Layer.h"
#include "Pooling.h"


class LayerPool: public Layer {
public:
    LayerPool(int pool_size,int stride,Pooling* pool);
    LayerPool(const LayerPool& orig);
    virtual ~LayerPool();
   
    virtual void intialization(Size input_size, int input_type, Size output_size, int output_type);
    virtual void set_weights(Mat weights);
    virtual void set_biases(Mat biases);
    virtual void feed_forward(Mat x);
    virtual void back_pass(Mat y);
    virtual void apply_gradient(double alpha);
    Mat pool_up(Mat y);
    
    
    Pooling* pool;
    Size pool_size;
    int stride;
    bool is_before_fc;
private:
    virtual void compute_z();
    virtual void compute_a();
    virtual void compute_delta();
    virtual void compute_gradient();
};

#endif /* LAYERPOOL_H */

