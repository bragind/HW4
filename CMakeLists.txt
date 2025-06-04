cmake_minimum_required(VERSION 3.20)
project(homework_4 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(url_encoder_decoder STATIC src/point.cpp src/polygon.cpp)

add_subdirectory(app)
add_subdirectory(test)