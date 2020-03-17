#include "../heap/MaxHeap.h"

class PriorityQueue : public MaxHeap
{
private:
public:
    PriorityQueue();
    PriorityQueue(int *data,int n);
    ~PriorityQueue();
    int insert(int value);
    int increaseValue(int pos,int newvalue);
    int extractMax();
    int getMax();
    void print();
};
