cmake_minimum_required(VERSION 2.8)
project( VideoProcLib )
find_package( OpenCV REQUIRED )

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -fsycl -fsycl-targets=nvptx64-nvidia-cuda -std=c++17 -Wno-unknown-cuda-version")

include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include/")
file(GLOB SRCFILES src/*.cpp)

add_executable( vplx main.cpp ${SRCFILES})
target_link_libraries( vplx ${OpenCV_LIBS} )