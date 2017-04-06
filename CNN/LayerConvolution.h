/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LayerConvolution.h
 * Author: rif
 *
 * Created on March 24, 2017, 2:01 PM
 */

#ifndef LAYERCONVOLUTION_H
#define LAYERCONVOLUTION_H

#include "Layer.h"
#include "Activation.h"


class LayerConvolution: public Layer {
public:
    LayerConvolution(int number_of_feature, int kernel_size, int stride, Activation* act);
    virtual ~LayerConvolution();

    virtual void feed_forward(Mat x);
    virtual void intialization();
    
    
private:
    int number_of_feature;
    Size kernel_size;
    int stride;
    Point point_conv;
    
    
    
    virtual void compute_z();
    virtual void compute_a();
};

#endif /* LAYERCONVOLUTION_H */

