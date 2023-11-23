cmake_minimum_required(VERSION 3.15)
project(Face_Detection)

set(CMAKE_CXX_STANDARD 23)
find_package(OpenCV REQUIRED)

# Add the executable and specify its source file
add_executable(Face_Detection main.cpp)

# Specify the include directories for the executable
target_link_directories(Face_Detection PRIVATE
    "C:/Program Files (x86)/Eclipse Paho C/lib"
    "C:/Program Files (x86)/paho-mqtt-cpp/lib"
)

# Specify the include directories for external dependencies
target_include_directories(Face_Detection PRIVATE
    ${OpenCV_INCLUDE_DIRS}
    "C:/Program Files (x86)/paho-mqtt-cpp/include"
    "C:/Program Files (x86)/Eclipse Paho C/include"
)

# Specify the library directories for external dependencies
link_directories(
    "C:/Program Files (x86)/Eclipse Paho C/lib"
    "C:/Program Files (x86)/paho-mqtt-cpp/lib"
)

# Specify the libraries to link against
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)
target_link_libraries(Face_Detection  ${OpenCV_LIBS} paho-mqttpp3-static paho-mqtt3c paho-mqtt3a)
