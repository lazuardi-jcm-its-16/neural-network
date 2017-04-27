/*
 * Copyright (C) INFOGLOBAL TEKNOLOGI SEMESTA, PT - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential.
 */

/* 
 * File:   LayerConvolution.h
 * Author: RIF <arif.lazuardi@infoglobal.co.id>
 *
 * Created on March 24, 2017, 2:01 PM
 */

#ifndef LAYERCONVOLUTION_H
#define LAYERCONVOLUTION_H

#include "Layer.h"
#include "Activation.h"

typedef enum {same,valid,full} convolution_type;

class LayerConvolution: public Layer {
public:
    LayerConvolution(int number_of_feature, int kernel_size, int stride, Activation* act);
    LayerConvolution(const LayerConvolution& orig);
    virtual ~LayerConvolution();

    virtual void intialization(Size input_size, int input_type, Size output_size, int output_type);
    virtual void feed_forward(Mat x);
    virtual void back_pass(Mat y);
    virtual void apply_gradient(double alpha);
    virtual void set_weights(Mat weights);
    virtual void set_biases(Mat biases);

    Mat convolve_valid_ff(Mat inputs,Mat kernels,Mat biases);
    Mat convolve_valid_bp(Mat inputs,Mat kernels);
    Mat convolve_full_bp(Mat inputs, Mat kernels);
    Mat conv2D(Mat input, Mat kernel, convolution_type type);


    int number_of_feature;
    Size kernel_size;
    int stride;
    Point point_conv;
    
private:
    
    
    virtual void compute_z();
    virtual void compute_a();
    virtual void compute_delta();
    virtual void compute_gradient();
};

#endif /* LAYERCONVOLUTION_H */

