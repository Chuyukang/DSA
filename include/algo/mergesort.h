#ifndef DSA_MERGESORT_H
#define DSA_MERGESORT_H

#include "sort.h"

class mergesortAlgo : public sortAlgo {
public:
    mergesortAlgo() = default;
    ~mergesortAlgo() = default;

    void sort(std::vector<int> &vec) override;
private:
    std::vector<int> temp_;

    void mergesort(int *arr, int left, int right);
};

#endif //DSA_MERGESORT_H
