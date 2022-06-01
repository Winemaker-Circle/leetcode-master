cmake_minimum_required(VERSION 3.21)
project(leetcode_master)

set(CMAKE_CXX_STANDARD 14)

include_directories(test)

add_executable(leetcode_master
        test/yzc/0508/1.twoSum.cpp)
add_executable(leetcodeTemplate test/yzc/common/leetcodeTemplate.cpp)
add_executable(027RemoveElement test/yzc/0515/027RemoveElement.cpp)
add_executable(026RemoveDuplicates test/yzc/0515/026RemoveDuplicates.cpp)
add_executable(35.SearchInsertPosition test/yzc/0526/35.SearchInsertPosition.cpp)
add_executable(BinarySearch test/yzc/common/BinarySearch.cpp)
add_executable(53.MaximumSubarray test/yzc/0526/53.MaximumSubarray.cpp)
add_executable(509.FibonacciNumber test/yzc/0601/509.FibonacciNumber.cpp)
add_executable(66.PlusOne test/yzc/0601/66.PlusOne.cpp)
add_executable(88.MergeSortedArray test/yzc/0601/88.MergeSortedArray.cpp)
add_executable(735.AsteroidCollision test/yzc/0601/735.AsteroidCollision.cpp)