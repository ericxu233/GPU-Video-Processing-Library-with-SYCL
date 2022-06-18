#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <CL/sycl.hpp>
#include <string>
#include <string.h>
#include <opencv2/videoio.hpp>

using namespace std;
//namespace sycl = cl::sycl;

extern unsigned long global_memory_size;
extern u_int local_memory_size;
extern u_int work_item_dim[3];