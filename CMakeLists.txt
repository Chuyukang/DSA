cmake_minimum_required(VERSION 3.15)
project(DSA)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)


# Dependencies
cmake_policy(SET CMP0135 NEW)
include(FetchContent)

# googletest
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# google benchmark
FetchContent_Declare(
        benchmark
        URL https://github.com/google/benchmark/archive/refs/tags/v1.8.0.zip
)
FetchContent_MakeAvailable(benchmark)

enable_testing()

add_executable(
        test_sort
        tests/test_sort.cpp
        src/algo/sort/quickSort.cpp
        src/algo/sort/heapSort.cpp
)
target_link_libraries(test_sort GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(test_sort)

add_executable(
        bench_sort
        tests/bench_sort.cpp
        src/algo/sort/quickSort.cpp
        src/algo/sort/heapSort.cpp
)
target_link_libraries(bench_sort benchmark::benchmark)

add_executable(test_heap tests/test_heap.cpp tests/bench_sort.cpp)
add_executable(test_pq tests/test_pq.cpp)
add_executable(test_tree tests/test_tree.cpp)
