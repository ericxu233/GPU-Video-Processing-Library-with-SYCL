#include "common.hpp"
#include "VPL.hpp"

#define DISPLAYDEVICE 1

/*
    Global Variables
*/
unsigned long global_memory_size;
u_int local_memory_size;
u_int work_item_dim[3];

/*
    Main helper functions
*/
void query_device(sycl::device& device);


int main(int argc, char** argv )
{
    if ( argc <= 2 ) {
        cout << "vplx error: Insufficient enough arguments." << endl;
        return 1;
    }

    sycl::device device = sycl::default_selector{}.select_device();
    
    sycl::queue queue(device, [] (sycl::exception_list el) {
       for (auto ex : el) { std::rethrow_exception(ex); }
    } );

    query_device(device);

    string in_name(argv[2]);


    Video myVid(in_name, queue, "out.mp4");

    if (strcmp(argv[1], "--grey-out") == 0) {
        string cp(argv[2]);
        myVid.grey_out();
    }
    
    return 0;
}

void query_device(sycl::device& device) {
    if (!DISPLAYDEVICE) return;

    global_memory_size = device.get_info<sycl::info::device::global_mem_size>();
    local_memory_size = device.get_info<sycl::info::device::local_mem_size>();
    work_item_dim[0] = device.get_info<sycl::info::device::max_work_item_sizes>()[0];
    work_item_dim[1] = device.get_info<sycl::info::device::max_work_item_sizes>()[1];
    work_item_dim[2] = device.get_info<sycl::info::device::max_work_item_sizes>()[2];

    cout << "Device name: " << device.get_info<sycl::info::device::name>() << endl;
    cout << "GPU memory size: " << global_memory_size << " bytes" << endl;
    cout << "GPU work gorup chache size: " << local_memory_size << " bytes" << endl;
    cout << "Work item dimensions: " << work_item_dim[0] << ", " << work_item_dim[1] << ", " << work_item_dim[2] << endl;

}