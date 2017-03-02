/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NN.h
 * Author: rif
 *
 * Created on February 27, 2017, 5:05 PM
 */

#ifndef NN_H
#define NN_H

#include <X11/Xlib.h>
#include <new>
#include <opencv2/core.hpp>

#include "DataPreparation.h"

using namespace cv;

class NN {
public:
    NN(int * layers, int length_of_layers); // CLEAR
    NN(const NN& orig); // NOT YET TEST
    virtual ~NN(); // NOT YET TEST
    
    void sgd(DataPreparation * data, int epochs, int mini_batch_size, double learning_rate); //stochastic_gradient_descent
    void update_mini_batch(Mat * mini_batch_train, Mat * mini_batch_train_label, int mini_batch_size, double learining_rate);
    void backprop(Mat train_images, Mat train_labels);
    Mat cost_derivative(Mat output_activations, Mat y_target);
    int evaluate(DataPreparation * data);
    Mat feed_forward(Mat test_images);
    
    
    int * layers;
    int length_of_layers;
    Mat * biases;
    Mat * weights;
    void initialization_biases_and_weights(Mat * biases, Mat * weights, bool fill_random);
    struct Nabla {
        Mat * nabla_biases;
        Mat * nabla_weights;
    } delta_nabla;
private:
    
};

#endif /* NN_H */

