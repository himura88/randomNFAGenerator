cmake_minimum_required(VERSION 3.2)
project(UniformRandomNFAGenerator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(UniformRandomNFAGenerator ${SOURCE_FILES} StreamGenerator.cpp StreamGenerator.h RandomNFAGenerator.cpp RandomNFAGenerator.h)