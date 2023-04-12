cmake_minimum_required(VERSION 3.15)
project(DSA)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(test_heap tests/test_heap.cpp)
add_executable(test_pq tests/test_pq.cpp)
add_executable(test_tree tests/test_tree.cpp)
