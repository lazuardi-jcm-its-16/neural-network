/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rif
 *
 * Created on February 23, 2017, 2:18 PM
 */
#include <iostream>
#include <cstdlib>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
    
using namespace std;
using namespace cv;

/*
 * 
 */

static void window_sliding(string title, Mat img)
{
    Mat tmp = img.clone();
    int step_x = 0; // normally 4 to 8 pixels
    int step_y = 0;
    int window_size = 32;
    RNG rng(12345);

    for(int i=0; i<img.rows/4; ++i) 
    {
        for(int j=0; j<img.cols/4; ++j)
        {
            Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
            Rect r;
            r.x = step_x;
            r.y = step_y;
            r.width = window_size;
            r.height = window_size;
            rectangle(tmp,r,color,1,8,0);
            imshow(title, tmp);
            //waitKey(5);
            tmp = img.clone();
            step_x += 4;
        }
        step_x = 0;
        step_y += 4;
    }
}

int main(int argc, char** argv) {
    
    Mat src = imread("plane2.jpg",IMREAD_GRAYSCALE);
    if( src.empty() )
    { 
        printf(" No data! -- Exiting the program \n");
        return -1; 
    }
    Mat tmp = src;
    Mat dst = tmp;
    
    string title = "image";
    window_sliding(title,src);
    
    for(int i=0; i<3; ++i) 
    {
        pyrDown(tmp, dst, Size( tmp.cols/2, tmp.rows/2 ) );
        title.append("x");
        window_sliding(title,dst);
        tmp=dst;
    }
    waitKey();
    
    return 0;
}

