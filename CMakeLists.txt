cmake_minimum_required(VERSION 3.21)
project(leetcode_master)

set(CMAKE_CXX_STANDARD 14)

include_directories(test)

add_executable(leetcode_master
        test/twoSum.cpp)
add_executable(leetcodeTemplate test/leetcodeTemplate.cpp)
add_executable(027RemoveElement test/027RemoveElement.cpp)
add_executable(026RemoveDuplicates test/026RemoveDuplicates.cpp)