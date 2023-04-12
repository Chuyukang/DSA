#include "MaxHeap.h"

template<typename T>
class MaxPriorityQueue: public MaxHeap<T>
{
private:
public:
    MaxPriorityQueue();
    MaxPriorityQueue(T *data,int n);
    ~MaxPriorityQueue();
    int insert(T value);
    int increaseValue(int pos,T newvalue);
    T extractMax();
    T getMax();
    void print();
};

template<typename T>
MaxPriorityQueue<T>::MaxPriorityQueue(){}
template<typename T>
MaxPriorityQueue<T>::MaxPriorityQueue(T *data,int n):MaxHeap<T>(data,n) { }
template<typename T>
MaxPriorityQueue<T>::~MaxPriorityQueue() { }

template<typename T>
T MaxPriorityQueue<T>::getMax()
{
    return MaxHeap<T>::array[0];
}
template<typename T>
int MaxPriorityQueue<T>::increaseValue(int pos,T newValue)
{
    if(newValue<=MaxHeap<T>::array[pos])
        return -1;
    MaxHeap<T>::array[pos] = newValue;
    return MaxHeap<T>::percolateUP(pos);
}
template<typename T>
int MaxPriorityQueue<T>::insert(T value)
{
    MaxHeap<T>::size ++;
    if(MaxHeap<T>::capacity<=MaxHeap<T>::size)
        MaxHeap<T>::expandArray(MaxHeap<T>::capacity*2);
    MaxHeap<T>::array[MaxHeap<T>::size-1] = value-1;
    return increaseValue(MaxHeap<T>::size-1,value);
}
template<typename T>
T MaxPriorityQueue<T>::extractMax()
{
    int ans = MaxHeap<T>::array[0];
    MaxHeap<T>::array[0] = MaxHeap<T>::array[MaxHeap<T>::size-1];
    MaxHeap<T>::size --;
    MaxHeap<T>::percolateDown(0);
    return ans;
}
template<typename T>
void MaxPriorityQueue<T>::print()
{
    for(int i=0;i<MaxHeap<T>::size;i++)
        std::cout << MaxHeap<T>::array[i] << (i<MaxHeap<T>::size-1?" ":"\n");
}