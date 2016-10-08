cmake_minimum_required(VERSION 3.5)
project(ParseID)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Parser.cpp)
add_executable(ParseID ${SOURCE_FILES})