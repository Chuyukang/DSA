#include<iostream>
#include"ds/MaxPriorityQueue.h"

int main()
{
    int data[8]={4,5,1,3,2,6,9,7};
    MaxPriorityQueue<int> priorityQueue(data,8);
    priorityQueue.print();

    std::cout << "getMax:" << priorityQueue.getMax() << "\n";

    std::cout << "extract max:" << priorityQueue.extractMax() << "\n";
    priorityQueue.print();

    //increase value
    priorityQueue.increaseValue(4,10);
    priorityQueue.print();

    priorityQueue.insert(11);
    priorityQueue.print();

    return 0;
}