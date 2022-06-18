#include "Video.hpp"


Video::Video(const string& in_name, string out_name = "out.blah") {
    cap = cv::VideoCapture(in_name);
    if(!cap.isOpened()) {
        cout << "Error: unable to open the video\n";
        exit(-1);     
    }

    width = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
    height = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT ));

    double FPS = cap.get(cv::CAP_PROP_FPS);

    cv::Size S = cv::Size(width, height);

    out.open(out_name, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), FPS, S, true);

    if (!out.isOpened()) {
        cout  << "Error: Could not open the output video for write. " << endl;
        exit(1);
    }

    cv::Mat img;

    while (1) {
        cap >> img;
        if (img.empty()) break;
        out << img;
    }
}

Video::~Video() {
    
}
