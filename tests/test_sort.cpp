#include <vector>
#include <gtest/gtest.h>
#include "algo/sort.h"
#include "algo/quicksort.h"
#include "algo/heapsort.h"
#include "algo/mergesort.h"

void check_correctness(const std::vector<int>& vec) {
    for(int i=1;i<vec.size();i++) {
        EXPECT_LE(vec.at(i-1), vec.at(i));
    }
}

TEST(SortCorrectTest, QuickSort) {
    std::vector<std::vector<int>> testCases{{}, {1}, {1,1}, {1,3,2} ,{1,2,3}, {1,1,1}};

    sortAlgo *sorter=new quicksortAlgo();

    for(auto& vec:testCases) {
        sorter->sort(vec);
        check_correctness(vec);
    }
}

TEST(SortCorrectTest, HeapSort) {
    std::vector<std::vector<int>> testCases{{}, {1}, {1,1}, {1,3,2} ,{1,2,3}};

    sortAlgo *sorter=new heapsortAlgo();

    for(auto& vec:testCases) {
        sorter->sort(vec);
        check_correctness(vec);
    }
}

TEST(SortCorrectTest, MergeSort) {
    std::vector<std::vector<int>> testCases{{}, {1}, {1,1}, {1,3,2} ,{1,2,3}};

    sortAlgo *sorter=new mergesortAlgo();

    for(auto& vec:testCases) {
        sorter->sort(vec);
        check_correctness(vec);
    }
}
