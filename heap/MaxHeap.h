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
    void percolateDown(int i);
    int percolateUP(int pos);
    void buildHeap();
    //for test
    void print();
};
