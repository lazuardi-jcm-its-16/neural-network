/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NN2.h
 * Author: rif
 *
 * Created on February 27, 2017, 5:05 PM
 */

#ifndef NN2_H
#define NN2_H

#include <X11/Xlib.h>
#include <new>
#include <opencv2/core.hpp>

#include "DataPreparation.h"
#include "NNDefaultWeightsBiases.h"

using namespace cv;

class NN2 {
public:
    NN2(DataPreparation * data, int * layers, int length_of_layers); // CLEAR
    NN2(const NN2& orig); // NOT YET TEST
    virtual ~NN2(); // NOT YET TEST
    
    NNDefaultWeightsBiases nn;
    
    void sgd(int epochs, int mini_batch_size, double learning_rate); //stochastic_gradient_descent
    void update_mini_batch(Mat * mini_batch_train, Mat * mini_batch_train_label, int mini_batch_size, double learining_rate);
    void backprop(Mat train_images, Mat train_labels);
    Mat cost_derivative(Mat output_activations, Mat y_target);
    int evaluate(DataPreparation * data);
    Mat feed_forward(Mat test_images);
private:
    
};

#endif /* NN2_H */

