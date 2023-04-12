#include<iostream>
#include<cmath>

const int FACTOR = 10;
const int SIZE = 10;
const int NUM = 5;

void insertSort(double array[],int n)
{
    for(int i=1;i<n;i++)
    {
        double key = array[i];
        int j=i;
        for(;j>0&&array[j-1]>key;j--)
            array[j] = array[j-1];
        array[j] = key;
    }
}
void bucketSort(double array[],int n)
{
    //初始化数据结构
    double* listArray[NUM];
    int listSize[NUM];
    for(int i=0;i<NUM;i++){
        listArray[i] = new double[SIZE];
        listSize[i] = 0;
    }

    for(int i=0;i<n;i++)
    {
        int index = (int)floor(array[i]*NUM);
        listArray[index][listSize[index]] = array[i];
        listSize[index]++;
    }

    for(int i=0;i<NUM;i++)
        insertSort(listArray[i],listSize[i]);
    int count = 0;
    for(int i=0;i<NUM;i++)
    {
        for(int j=0;j<listSize[i];j++)
        {
            array[count] = listArray[i][j];
            count++;
        }
    }
    //释放数据结构
    for(int i=0;i<NUM;i++)
        delete[] listArray[i];
}
double* preProcess(int array[],int n,int factor)
{
    double *temp = new double[n];
    for(int i=0;i<n;i++)
        temp[i] = array[i] / (double)factor;
    return temp;
}
void postProcess(int array[],double result[],int n,int factor)
{
    for(int i=0;i<n;i++)
        array[i] = (int)(result[i] * factor);
    delete[] result;
}
void sort(int array[],int n)
{
    double* temp = preProcess(array,n,FACTOR);
    bucketSort(temp,n);
    postProcess(array,temp,n,FACTOR);
}