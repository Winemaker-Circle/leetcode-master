cmake_minimum_required(VERSION 3.21)
project(leetcode_master)

set(CMAKE_CXX_STANDARD 14)

include_directories(test)

add_executable(leetcode_master
        test/twoSum.cpp)
