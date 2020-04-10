#include<iostream>
#include"MaxHeap.h"

int main()
{
    int data[8]={4,5,1,3,2,6,9,7};
    MaxHeap<int> heap(data,8);
    heap.print();
    return 0;
}