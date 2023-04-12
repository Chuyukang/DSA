#include<algorithm>

/* | <=pivot | >pivot  | ...  | pivot |*/
/* |        i|         | j             */
int partition(int array[],int p,int r)
{
    int x = array[r];
    int i = p-1;
    for(int j=p;j<r;j++)
    {
        if(array[j]<=x)
        {
            i=i+1;
            std::swap(array[i],array[j]);
        }
    }
    std::swap(array[i+1],array[r]);
    return i+1;
}
void quickSort(int array[],int low,int high)
{
    if(low>=high)
        return ;
    int pivot = partition(array,low,high);
    quickSort(array,low,pivot-1);
    quickSort(array,pivot+1,high);
}

void sort(int array[],int n)
{
    quickSort(array,0,n-1);
}
