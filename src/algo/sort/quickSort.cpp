#include "algo/sort.h"
#include "algo/quicksort.h"
#include <cassert>

int partition(int arr[], int l, int r)
{
    int i=l,j=r;
    int pivot=arr[l]; // a hole in arr[i]
    while(i<j) {
        while(i<j && arr[j] >= pivot)
            j--;
        arr[i] = arr[j]; // hole moved to arr[j], trivial if i==j
        while(i<j && arr[i] <= pivot)
            i++;
        arr[j] = arr[i]; // hole moved back to arr[i], trivial if i==j
    }
    // assert(i==j);

    arr[i] = pivot; // save pivot to the hole
    return i;
}
void quickSort(int array[],int low,int high)
{
    if(low>=high)
        return ;
    int pivot = partition(array,low,high);
    quickSort(array,low,pivot-1);
    quickSort(array,pivot+1,high);
}

void quicksortAlgo::sort(std::vector<int> &vec) {
    quickSort(vec.data(), 0, vec.size()-1);
}
