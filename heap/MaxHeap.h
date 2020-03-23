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
    int getSize();
    void percolateDown(int i);
    int percolateUP(int pos);
    void buildHeap();
    int getData(int result[],int n);
    //for test
    void print();
};
