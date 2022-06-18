#include "common.hpp"


// This file implements a video class for image parsing and 
// batching to the GPU.


class Video {
public:
    Video(const string& name, string rename);
    ~Video();

private:
    cv::VideoCapture cap;
    cv::VideoWriter out;
    int height;
    int width;
    
public:


};