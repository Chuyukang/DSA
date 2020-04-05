#include<iostream>

using namespace std;

extern int getMaxValue(int p[],int n,int length);

int main()
{
    int array[10]={1,5,8,9,10,17,17,20,24,30};
    int length = 5;
    cout << "The Max Value could get from rod(" << length <<") is " 
        << getMaxValue(array,10,length) << "\n";
    return 0;
}