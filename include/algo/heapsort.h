#ifndef DSA_HEAPSORT_H
#define DSA_HEAPSORT_H

#include "algo/sort.h"

class heapsortAlgo :public sortAlgo {
public:
    heapsortAlgo()=default;
    void sort(std::vector<int> &vec) override;
};


#endif //DSA_HEAPSORT_H
