#include <cstddef>
#include "algo/mergesort.h"

void mergeSortedHalf(int arr[], int left, int right, std::vector<int>& temp_) {
    int mid = (left+right) / 2;

    int i=left,j=mid;
    int index = left;

    /* merged to temp_ */
    while (i<mid&&j<right) {
        if(arr[i]<=arr[j]) {
            temp_[index] = arr[i];
            index++;
            i++;
        } else {
            temp_[index] = arr[j];
            index++;
            j++;
        }
    }
    while (i<mid) {
        temp_[index] = arr[i];
        index++;
        i++;
    }
    while (j<right) {
        temp_[index] = arr[j];
        index++;
        j++;
    }

    /* copy back to arr */
    for(int k=left;k<right;k++) {
        arr[k] = temp_[k];
    }
}

/*
 * mergesort:
 *      merge sort arr in the interval: [left,right)
 *
 * Time efficiency: O(nlogn)
 * Space efficiency: O(n)
 *      only need one vector, temp_ vector is only used by one merge simultaneously
 */
void mergesortAlgo::mergesort(int arr[], int left, int right) {
    if((right-left)<2) {
        return;
    }

    int mid = (left+right) / 2;
    mergesort(arr, left, mid);
    mergesort(arr, mid, right);

    mergeSortedHalf(arr, left, right, temp_);
}

void mergesortAlgo::sort(std::vector<int> &vec) {
    size_t n = vec.size();
    temp_.resize(n, 0);

    mergesort(vec.data(), 0, n);
}

