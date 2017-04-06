/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CNN2.cpp
 * Author: rif
 * 
 * Created on March 6, 2017, 2:43 PM
 */

#include "CNN2.h"
#include "ActSigmoid.h"
#include "ActRelu.h"

CNN2::CNN2(Size size_input, Size size_convolution, Size size_pool, Size size_output, int number_feature_maps) {
    /*
    
    // jumlah feature maps di setiap hidden layer
    number_of_feature_maps = number_feature_maps;
    
    // ukuran matriks layer input
    size_of_input_layer = size_input;
    
    // ukuran matriks local field (untuk konvolusi)
    size_of_conv = size_convolution;
    // ukuran matriks layer konvolusi (hasil dari local_field * weight_of_local_field + bias)
    size_of_conv_layer.width = size_of_input_layer.width - size_of_conv.width + 1;
    size_of_conv_layer.height = size_of_input_layer.height - size_of_conv.height + 1;
    conv_layer.create(size_of_conv_layer,CV_32FC(number_of_feature_maps));
    
    // ukuran matriks pooling (untuk max pooling)
    size_of_pool = size_pool;
    // ukuran matriks layer pool (hasil dari layer konvolusi
    size_of_pool_layer.width = size_of_conv_layer.width/size_of_pool.width;
    size_of_pool_layer.height = size_of_conv_layer.height/size_of_pool.height;
    pool_layer.create(size_of_pool_layer,CV_32FC(number_of_feature_maps));
    
    // ukuran matriks neuron output
    size_of_output_layer = size_output;
    output_layer.create(size_of_output_layer,CV_32F);
    
    initialization_weights();
    initialization_biases();
    
    //cout << weights_of_feature_maps[0].at<Vec2f>(0,0)[19] << endl;
    //cout << biases_of_feature_maps.at<Vec2f>(0,0)[19] << endl;
    //cout << conv_layer.at<Vec2f>(0,0)[5] << endl; */
}

CNN2::CNN2(const CNN2& orig) {
}

CNN2::~CNN2() {
}

void CNN2::initialization_weights() {
    /*
    // inisiasi weights untuk layer input sebanyak jumlah feature_maps matriks konvolusi layer
    // inisiasi weights dengan bilangan random distribusi gaussian/normal dengan mean=0 dan std=1
    weights_of_feature_maps.create(size_of_conv, CV_32FC(number_of_feature_maps));
    randn(weights_of_feature_maps,0,1);
    
    weights_of_fully_conn_maps.create(size_of_output_layer.height,pool_layer.rows*pool_layer.cols*pool_layer.channels(), CV_32F);
    randn(weights_of_fully_conn_maps,0,1);
    */
}

void CNN2::initialization_biases() {
    /*
    // inisiasi biases untuk layer input sebanyak jumlah feature_maps matriks konvolusi layer
    // inisiasi biases dengan bilangan random distribusi gaussian/normal dengan mean=0 dan std=1
    biases_of_feature_maps.create(1,1, CV_32FC(number_of_feature_maps));
    randn(biases_of_feature_maps,0,1);
    
    biases_of_fully_conn_maps.create(size_of_output_layer, CV_32F);
    randn(biases_of_fully_conn_maps,0,1);
    */
}

void CNN2::train_data(DataPreparation *data, int epochs) {
    /*
    for(int i=0; i<data->number_of_train_data; ++i) {
        Mat input_train = data->train_images[i];
        input_train.convertTo(input_train,CV_32F);
        
        Mat target_train = data->train_labels[i];
        target_train.convertTo(target_train,CV_32F);
        
        back_propagation(input_train*(1.0/255.0),target_train); 
    }
    */
}

void CNN2::back_propagation(Mat input_train, Mat target_train) {
    /*
    // feed-forward
    convolutional_layer(input_train);
    
    // cout << target_train << endl;
    // cout << Sigmoid::Compute(output_layer) << endl;
    
    // backward-pass
    Mat delta_3 = cost_derivative(Sigmoid::Compute(output_layer),target_train).mul(Sigmoid::ComputePrime(output_layer));
    
    Mat delta_2 = (weights_of_fully_conn_maps.t()*delta_3).mul(Sigmoid::ComputePrime(pool_vector));
    vector<float> pool(delta_2.rows*delta_2.cols);
    if(delta_2.isContinuous()) {
        pool.assign((float*)delta_2.datastart, (float*)delta_2.dataend);
    }
    Mat pool_temp(size_of_pool_layer,CV_32FC(number_of_feature_maps));
    memcpy(pool_temp.data, pool.data(), pool.size()*sizeof(float));
    
    Mat conv_temp = pool_temp;
    pyrUp(pool_temp,conv_temp,size_of_conv_layer);
    
    cout << conv_temp << endl;
    //biases_of_fully_conn_maps = delta_3;
    //weights_of_fully_conn_maps = delta_3 * pool_vector.t();
    */
}



void CNN2::convolutional_layer(Mat local_field_of_imsource) {
    /*
    for(int j=0; j<number_of_feature_maps; ++j) {   
        Mat kernel(size_of_conv,CV_32F);
        extractChannel(weights_of_feature_maps,kernel,j);
        
        for(int x=0; x<size_of_conv_layer.width; ++x) {
            for(int y=0; y<size_of_conv_layer.height; ++y) {
                Point point(y,x);
                Rect rect(point,size_of_conv);
                Mat local_field = local_field_of_imsource(rect);
                
                conv_layer.at<Vec20f>(x,y)[j] = sum(local_field.mul(kernel)).val[0] + biases_of_feature_maps.at<Vec20f>(0,0)[j];  
            }
        } 
        
        Mat conv_layer_by_index(size_of_conv_layer,CV_32F);
        extractChannel(conv_layer,conv_layer_by_index,j);
        
        pooling_layer(Relu::Compute(conv_layer_by_index),j);
    }
    
    fully_connected_layer(pool_layer);
    */
}

void CNN2::pooling_layer(Mat conv_layer_by_index, int index) {
    /*
    double min_val,max_val;
    Point min_loc,max_loc;
    minMaxLoc(conv_layer_by_index,&min_val,&max_val,&min_loc,&max_loc,Mat());
    cout << min_val << " --- " << max_val << endl;
    
    for(int x=0; x<size_of_pool_layer.width; ++x) {
        for(int y=0; y<size_of_pool_layer.height; ++y) {
            Point point(y*size_of_pool.width,x*size_of_pool.height);
            Rect rect(point, size_of_pool);
            Mat pool_field = conv_layer_by_index(rect);
            
            minMaxLoc(pool_field,&min_val,&max_val,&min_loc,&max_loc,Mat());
            pool_layer.at<Vec20f>(x,y)[index] = max_val;
        }
    }
    
    Mat pool_layer_by_index(size_of_conv_layer,CV_32F);
    extractChannel(conv_layer,pool_layer_by_index,index);
    */
}

void CNN2::fully_connected_layer(Mat pool_layer) {
    /*
    int length = pool_layer.rows*pool_layer.cols*pool_layer.channels();
    vector<float> pool(length);
    if(pool_layer.isContinuous()) {
        pool.assign((float*)pool_layer.datastart, (float*)pool_layer.dataend);
    }
    
    pool_vector.create(length,1,CV_32F);
    memcpy(pool_vector.data, pool.data(), pool.size()*sizeof(float));
    
    output_layer = weights_of_fully_conn_maps * pool_vector + biases_of_fully_conn_maps;
    
    
    double min_val,max_val;
    Point min_loc,max_loc;
    minMaxLoc(weights_of_fully_conn_maps,&min_val,&max_val,&min_loc,&max_loc,Mat());
    cout << "****************" << endl;
    cout << min_val << " --- " << max_val << endl;
    
    minMaxLoc(pool_vector,&min_val,&max_val,&min_loc,&max_loc,Mat());
    cout << "****************" << endl;
    cout << min_val << " --- " << max_val << endl;
    
    minMaxLoc(biases_of_fully_conn_maps,&min_val,&max_val,&min_loc,&max_loc,Mat());
    cout << "****************" << endl;
    cout << min_val << " --- " << max_val << endl;
    
    minMaxLoc(output_layer,&min_val,&max_val,&min_loc,&max_loc,Mat());
    cout << "****************" << endl;
    cout << min_val << " --- " << max_val << endl;
    
    Mat relu = Relu::Compute(output_layer);
    minMaxLoc(relu,&min_val,&max_val,&min_loc,&max_loc,Mat());
    cout << "****************" << endl;
    cout << min_val << " --- " << max_val << endl;*/
}

Mat CNN2::cost_derivative(Mat output_activations, Mat y_target) {
    return output_activations-y_target;
}





