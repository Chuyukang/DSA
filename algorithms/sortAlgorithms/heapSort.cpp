#include "../../priorityQueue/MaxPriorityQueue.h"

const int SIZE = 20;

void heapSort(int array[],int n)
{
    //初始化并构建优先级队列
    //队列内数据需导出
    MaxPriorityQueue<int> pq(array,n);
    for(int i=n-1;i>=0;i--)
        array[i] = pq.extractMax();
}

void sort(int array[],int n)
{
    heapSort(array,n);
}