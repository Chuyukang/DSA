#include <iostream>
#include "ds/MaxHeap.h"
#include "ds/MinHeap.h"
using namespace std;

int main()
{
    int data[8]={4,5,1,3,2,6,9,7};
    MaxHeap<int> maxHeap(data,8);
    cout << "max heap:\n";
    maxHeap.print();
    cout << "\n---\n";

    MinHeap<int> minHeap(data,8);
    cout << "min heap:\n";
    minHeap.print();
    cout << "\n---\n";

    cout << "maxHeap.extractMax(): " << maxHeap.extractMax() << "\n";
    cout << "current max heap:\n";
    maxHeap.print();
    cout << "\n---\n";

    cout << "minHeap.extractMin(): " << minHeap.extractMin() << "\n";
    cout << "current min heap:\n";
    minHeap.print();
    cout << "\n---\n";

    return 0;
}