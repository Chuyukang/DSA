class MaxHeap
{
protected:
    int* array;
    int size;
    int capacity;
    int getParent(int x);
    int expandArray(int newCapacity);
public:
    MaxHeap();
    MaxHeap(int* data,int n);
    ~MaxHeap();
    void heapify(int i);
    void buildHeap();
    //for test
    void print();
};
