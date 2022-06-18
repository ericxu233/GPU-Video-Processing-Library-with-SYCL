#pragma once
#include "common.hpp"


// This file implements a video class for image parsing and 
// batching to the GPU.


class Video {
public:
    Video(const string&, sycl::queue&, string);
    ~Video();
    void grey_out();

private:
    sycl::queue& q;
    cv::VideoCapture cap;
    cv::VideoWriter out;
    int height;
    int width;
    
private:
    void grey_out_kernel();



};