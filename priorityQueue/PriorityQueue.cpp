#include "PriorityQueue.h"
#include <iostream>

PriorityQueue::PriorityQueue(){}
PriorityQueue::PriorityQueue(int *data,int n):MaxHeap(data,n) { }
PriorityQueue::~PriorityQueue() { }

int PriorityQueue::getMax()
{
    return array[0];
}
int PriorityQueue::increaseValue(int pos,int newValue)
{
    if(newValue<=array[pos])
        return -1;
    int parent = getParent(pos);//parent指向上层待检查节点
    //debug
    // std::cout << "pos=" << pos << ", parent=" << parent << "\n";
    while (parent>=0&&array[parent]<newValue)
    {
        array[pos] = array[parent];
        pos = parent;
        parent = getParent(parent);
        // std::cout << "pos=" << pos << ", parent=" << parent << "\n";
    }
    array[pos] = newValue;
    return pos;
}
int PriorityQueue::insert(int value)
{
    size ++;
    if(capacity<=size)
        expandArray(capacity*2);
    array[size-1] = value-1;
    return increaseValue(size-1,value);
}
int PriorityQueue::extractMax()
{
    int ans = array[0];
    array[0] = array[size-1];
    size --;
    heapify(0);
    return ans;
}
void PriorityQueue::print()
{
    for(int i=0;i<size;i++)
        std::cout << array[i] << (i<size-1?" ":"\n");
}