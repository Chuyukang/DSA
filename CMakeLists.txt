cmake_minimum_required(VERSION 3.15)
project(DSA)

set(CMAKE_CXX_STANDARD 14)

add_executable(MaxeapTest heap/MaxHeap.h heap/test.cpp)
add_executable(MaxPriorityQueueTest priorityQueue/MaxPriorityQueue.h priorityQueue/test.cpp)
