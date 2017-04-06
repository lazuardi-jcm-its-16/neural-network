/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LayerFC.h
 * Author: rif
 *
 * Created on March 24, 2017, 2:10 PM
 */

#ifndef LAYERFC_H
#define LAYERFC_H

#include "Layer.h"


class LayerFC : public Layer {
public:
    LayerFC(Activation* act);
    LayerFC(const LayerFC& orig);
    virtual ~LayerFC();
    
    virtual void feed_forward(Mat x);
    virtual void intialization();
    void intialization(int number_of_neuron_input, int number_of_neuron_output);
    
    Mat x_as_vector;
private:
    int number_of_neuron_input;
    int number_of_neuron_output;
    
    Mat tranform_to_vector(Mat x);
    
    virtual void compute_z();
    virtual void compute_a();
};

#endif /* LAYERFC_H */

