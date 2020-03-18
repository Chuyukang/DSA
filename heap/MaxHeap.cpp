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
void MaxHeap::percolateDown(int i)
{
    int left = 2*i+1,right=2*i+2;
    if(left>=size && right >=size)
        return ;//退化递归基
    int pos=array[left]>array[i]?left:i;
    if(array[right]>array[pos])
        pos = right;
    
    if(pos!=i){
        std::swap(array[i],array[pos]);
        percolateDown(pos);
    }
    //else 为递归基
}
int MaxHeap::percolateUP(int pos)
{
    int key = array[pos];
    int parent = getParent(pos);//parent指向上层待检查节点
    while(parent>=0&&array[parent]<array[pos])//pos指向当前的“坑”，值已经向下迁移
    {
        array[pos] = array[parent];
        pos = parent;
        parent = getParent(parent);
    }

    array[pos] = key;
    return pos;
}
void MaxHeap::buildHeap()
{
    for(int i=size/2-1;i>=0;i--)//从第一个非叶子节点开始向下调整
        percolateDown(i);
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