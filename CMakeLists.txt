cmake_minimum_required(VERSION 3.23)
project(Face_Detection)

set(CMAKE_CXX_STANDARD 23)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(Face_Detection main.cpp)
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)
target_link_libraries(Face_Detection ${OpenCV_LIBS})
