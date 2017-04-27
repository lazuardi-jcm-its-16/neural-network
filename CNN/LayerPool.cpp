/*
 * Copyright (C) INFOGLOBAL TEKNOLOGI SEMESTA, PT - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential.
 */

/* 
 * File:   LayerPool.cpp
 * Author: RIF <arif.lazuardi@infoglobal.co.id>
 * 
 * Created on March 24, 2017, 2:08 PM
 */

#include "LayerPool.h"

LayerPool::LayerPool(int pool_size,int stride,Pooling* pool) : Layer(){
    this->type = pooling;
    this->pool_size.height = pool_size;
    this->pool_size.width = pool_size;
    this->stride = stride;
    this->pool = pool;
}

LayerPool::LayerPool(const LayerPool& orig) {
}

LayerPool::~LayerPool() {
}

void LayerPool::intialization(Size input_size, int input_type, Size output_size, int output_type) {
    x.create(input_size,input_type);
    z.create(output_size,output_type);
    a.create(output_size,output_type);
}

void LayerPool::set_weights(Mat weights) {

}

void LayerPool::set_biases(Mat biases) {

}

void LayerPool::feed_forward(Mat x) {
    this->x = x;
    compute_z();
    compute_a();
}


void LayerPool::compute_z() {
    z = pool->down_sampling(x,pool_size,stride);
}

void LayerPool::compute_a() {
    a = z;
}

void LayerPool::back_pass(Mat y) {
    e = y;
    compute_delta();
    compute_gradient();
}

void LayerPool::compute_delta() {
    delta = e;
}

void LayerPool::compute_gradient() {

}

Mat LayerPool::pool_up(Mat y) {
    return pool->up_sampling(y,pool_size,stride);
}

void LayerPool::apply_gradient(double alpha) {

}





