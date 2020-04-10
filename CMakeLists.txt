cmake_minimum_required(VERSION 3.15)
project(DSA)

set(CMAKE_CXX_STANDARD 14)

#add_executable(MaxeapTest heap/MaxHeap.h heap/test.cpp)
#add_executable(MaxPriorityQueueTest priorityQueue/MaxPriorityQueue.h priorityQueue/test.cpp)
#add_executable(HeapSortTest algorithms/sortAlgorithms/heapSort.cpp algorithms/sortAlgorithms/test.cpp)
#add_executable(QuickSortTest algorithms/sortAlgorithms/quickSort.cpp algorithms/sortAlgorithms/test.cpp)
#add_executable(DijkstraTest algorithms/Graph/Dijkstra.cpp graph/Graph.cpp)
#add_executable(BellmanFordTest algorithms/Graph/BellmanFord.cpp graph/Graph.cpp)
add_executable(AdjMatrixMulTest algorithms/Graph/AdjMatrixMul.cpp )
