#include "VPL.hpp"

void Video::grey_out() {
    u_int limit = UINT_MAX;
    uchar* host_data = sycl::malloc_host<uchar>(limit, q);
    cv::Mat img;
    u_int counter = 0;

    while (1) {
        cap >> img;
        if (img.empty()) break;
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                uchar b = img.at<cv::Vec3b>(i, j)[0] * 0.1;
                uchar g = img.at<cv::Vec3b>(i, j)[1] * 0.6;
                uchar r = img.at<cv::Vec3b>(i, j)[2] * 0.3;
                uchar grey = b*0.1 + g*0.6 + r*0.3;
                img.at<cv::Vec3b>(i, j)[0] = grey;
                img.at<cv::Vec3b>(i, j)[1] = grey;
                img.at<cv::Vec3b>(i, j)[2] = grey;
            }
        }

        out << img;
    }
}
