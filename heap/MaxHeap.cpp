#include<iostream>
#include<algorithm>
#include "MaxHeap.h"

MaxHeap::MaxHeap()
{
    capacity = 10;
    array = new int[capacity];
    size = 0;
}
MaxHeap::~MaxHeap()
{
    delete[] array;
}
MaxHeap::MaxHeap(int* data,int n)
{
    capacity = n;//可合理设置冗余？
    array = new int[capacity];
    for(int i=0;i<n;i++)
        array[i] = data[i];
    size = n;
    buildHeap();
}
int MaxHeap::getParent(int x)
{
    if(x%2)
        return (x-1)/2;
    else
        return x/2-1;
}
int MaxHeap::expandArray(int newCapacity)
{
    int *newArray=new int[newCapacity];
    for(int i=0;i<size;i++)
        newArray[i]=array[i];
    capacity = newCapacity;
    array = newArray;
}
void MaxHeap::heapify(int i)
{
    int left = 2*i+1,right=2*i+2;
    if(left>=size && right >=size)
        return ;//退化递归基
    int pos=array[left]>array[i]?left:i;
    if(array[right]>array[pos])
        pos = right;
    
    if(pos!=i){
        std::swap(array[i],array[pos]);
        heapify(pos);
    }
    //else 为递归基
}
void MaxHeap::buildHeap()
{
    for(int i=size/2-1;i>=0;i--)//从第一个非叶子节点开始向下调整
        heapify(i);
}
void MaxHeap::print()
{
    unsigned index=1,base=1;
    for(int i=0;i<size;i++){
        std::cout << array[i];
        if(index%base==0){
            std::cout << "\n";
            index=1;
            base <<= 1;
        }
        else{
            std::cout << " ";
            index++;
        }
    }
}