#include<iostream>

using namespace std;

extern void testMCMSolver(int p[],int size);

int main()
{
    int p[]={5,10,3,12,5,50,6};
    testMCMSolver(p,7);
    // int p[]={30,35,15,5,10,20,25};
    // testMCMSolver(p,7);
    return 0;
}