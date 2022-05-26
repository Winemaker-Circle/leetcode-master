cmake_minimum_required(VERSION 3.21)
project(leetcode_master)

set(CMAKE_CXX_STANDARD 14)

include_directories(test)

add_executable(leetcode_master
        test/yzc/twoSum.cpp)
add_executable(leetcodeTemplate test/yzc/leetcodeTemplate.cpp)
add_executable(027RemoveElement test/yzc/027RemoveElement.cpp)
add_executable(026RemoveDuplicates test/yzc/026RemoveDuplicates.cpp)
add_executable(35.SearchInsertPosition test/yzc/35.SearchInsertPosition.cpp)
add_executable(BinarySearch test/yzc/BinarySearch.cpp)
add_executable(53.MaximumSubarray test/yzc/53.MaximumSubarray.cpp)
add_executable(509.FibonacciNumber test/yzc/509.FibonacciNumber.cpp)