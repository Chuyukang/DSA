#ifndef DSA_QUICKSORT_H
#define DSA_QUICKSORT_H

#include "algo/sort.h"

class quicksortAlgo : public sortAlgo {
public:
    quicksortAlgo()=default;
    void sort(std::vector<int> &vec) override;
};

#endif //DSA_QUICKSORT_H
