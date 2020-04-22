#include <iostream>
#include "MaxHeap.h"
#include "MinHeap.h"
using namespace std;

int main()
{
    int data[8]={4,5,1,3,2,6,9,7};
    MaxHeap<int> maxHeap(data,8);
    maxHeap.print();
    cout << "\n";
    MinHeap<int> minHeap(data,8);
    minHeap.print();
    cout << "\n";
    cout << maxHeap.extractMax() << " " << minHeap.extractMin() << "\n";
    return 0;
}