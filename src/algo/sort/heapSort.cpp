#include "algo/sort.h"
#include "algo/heapsort.h"
#include "ds/MaxPriorityQueue.h"

void heapSort(int array[],int n)
{
    //初始化并构建优先级队列
    //队列内数据需导出
    MaxPriorityQueue<int> pq(array,n);
    for(int i=n-1;i>=0;i--)
        array[i] = pq.extractMax();
}

void heapsortAlgo::sort(std::vector<int> &vec) {
    heapSort(vec.data(), vec.size());
}
