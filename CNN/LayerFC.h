/*
 * Copyright (C) INFOGLOBAL TEKNOLOGI SEMESTA, PT - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential.
 */

/* 
 * File:   LayerFC.h
 * Author: RIF <arif.lazuardi@infoglobal.co.id>
 *
 * Created on March 24, 2017, 2:10 PM
 */

#ifndef LAYERFC_H
#define LAYERFC_H

#include "Layer.h"


class LayerFC : public Layer {
public:
    LayerFC(int neuron_size, Activation* act);
    LayerFC(const LayerFC& orig);
    virtual ~LayerFC();
    
    int number_of_neuron_input;
    int number_of_neuron_output;
    Mat x_as_vector;
    
    virtual void intialization(Size input_size, int input_type, Size output_size, int output_type);
    virtual void set_weights(Mat weights);
    virtual void set_biases(Mat biases);
    virtual void feed_forward(Mat x);
    virtual void back_pass(Mat y);
    virtual void apply_gradient(double alpha);
    
    Mat transform_to_vector(Mat x);
    Mat transform_to_image();
    Mat transform_to_image(int row, int col, int channel, Mat x);
private:
    virtual void compute_z();
    virtual void compute_a();
    virtual void compute_delta();
    virtual void compute_gradient();
};

#endif /* LAYERFC_H */

