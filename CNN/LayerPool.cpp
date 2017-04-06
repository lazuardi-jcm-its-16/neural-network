/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LayerPool.cpp
 * Author: rif
 * 
 * Created on March 24, 2017, 2:08 PM
 */

#include "LayerPool.h"

LayerPool::LayerPool(Pooling* pool) : Layer(){
    this->type = pooling;
    this->pool = pool;
}

LayerPool::LayerPool(const LayerPool& orig) {
}

LayerPool::~LayerPool() {
}

void LayerPool::intialization() {
    
}

void LayerPool::feed_forward(Mat x) {
    this->x = x;
    compute_z();
    compute_a();
}


void LayerPool::compute_z() {
    z = pool->down_sampling(x);
}

void LayerPool::compute_a() {
    a = z.clone();
}



