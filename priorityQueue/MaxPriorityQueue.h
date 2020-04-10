#include "../heap/MaxHeap.h"

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
MaxPriorityQueue<T>::MaxPriorityQueue(T *data,int n):MaxHeap(data,n) { }
template<typename T>
MaxPriorityQueue<T>::~MaxPriorityQueue() { }

template<typename T>
T MaxPriorityQueue<T>::getMax()
{
    return array[0];
}
template<typename T>
int MaxPriorityQueue<T>::increaseValue(int pos,T newValue)
{
    if(newValue<=array[pos])
        return -1;
    array[pos] = newValue;
    return percolateUP<T>(pos);
}
template<typename T>
int MaxPriorityQueue<T>::insert(T value)
{
    size ++;
    if(capacity<=size)
        expandArray(capacity*2);
    array[size-1] = value-1;
    return increaseValue(size-1,value);
}
template<typename T>
T MaxPriorityQueue<T>::extractMax()
{
    int ans = array[0];
    array[0] = array[size-1];
    size --;
    percolateDown(0);
    return ans;
}
template<typename T>
void MaxPriorityQueue<T>::print()
{
    for(int i=0;i<size;i++)
        std::cout << array[i] << (i<size-1?" ":"\n");
}