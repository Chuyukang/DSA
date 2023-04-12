#include<iostream>

using namespace std;

extern void sort(int array[],int n);

void print(int array[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout << array[i] << (i<n-1?" ":"\n");
    }
}
int main()
{
    int array[8]={2,4,7,6,1,8,5,3};
    print(array,8);

    sort(array,8);
    print(array,8);

    return 0;
}