#include<vector>

using namespace std;

class CutRodSolver
{
private:
    int *price;
    int size;
    int length;
public:
    CutRodSolver(int p[], int n, int length);
    ~CutRodSolver();
    int getMaxValue();
};

CutRodSolver::CutRodSolver(int p[], int _size, int _length)
{
    size = _size;
    price = new int[size];
    for(int i=0;i<size;i++)
        price[i] = p[i];
    length = _length;
}

CutRodSolver::~CutRodSolver()
{
    delete[] price;
}

int CutRodSolver::getMaxValue()
{
    if(length<=1)
        return price[length];
    
    int *array = new int[length+1];
    array[0] = price[0]; array[1] = price[1];

    for(int i=2;i<=length;i++)//array[i]
    {
        int max = 0;
        for(int j=1;j<=i;j++)//price[j]+array[i-j]
        {
            int temp = price[j] + array[i-j];
            if(temp>max)
                max = temp;
        }
        array[i] = max;
    }
    return array[length];
}

int getMaxValue(int p[],int n,int length)
{
    CutRodSolver solver(p,n,length);
    return solver.getMaxValue();
}