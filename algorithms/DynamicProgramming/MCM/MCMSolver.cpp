#include<vector>
#include<iostream>
#include<locale>
#include "../../../tree/Tree.h"

using namespace std;

void printFunc(const Tree<int>* root);

class MCMSolver
{
private:
    int *p;//矩阵维数序列
    int size;//维数序列的长度
    int num;//矩阵个数(size-1)

    vector<vector<int> > matrix;
    vector<vector<int> > infoMatrix;
public:
    MCMSolver(int _p[],int n);
    ~MCMSolver();
    int getMaxMULNum();
    unique_ptr<Tree<int>> getSolution(int i, int j);
    void printSolution();
};

MCMSolver::MCMSolver(int _p[],int n)
{
    p = new int[n];
    for(int i=0;i<n;i++)
        p[i] = _p[i];
    size = n;
    num = size-1;

    for(int i=0;i<=num;i++)//使用1 - num
    {
        matrix.push_back(vector<int>(num+1));
        infoMatrix.push_back(vector<int>(num+1));
    }
}

MCMSolver::~MCMSolver()
{
    delete[] p;
}
/*
r       j
 \      |
m[1,1] m[1,2] m[1,3] --i
       m[2,2] m[2,3]
              m[3,3]
*/
int MCMSolver::getMaxMULNum()
{
    for(int i=1;i<=num;i++)
        matrix[i][i] = 0;
    for(int r=2;r<=num;r++)//第r条斜线
    {
        for(int j=r,i=1;j<=num;i++,j++)//m[i, j]
        {
            int min = __INT_MAX__;//trick min初值
            for(int k=i;k<j;k++)
            {
                int temp = matrix[i][k] + matrix[k+1][j] + p[i-1]*p[k]*p[j];
                if(temp<min)
                {
                    min = temp;
                    infoMatrix[i][j] = k;
                }
            }
            matrix[i][j] = min;
        }
    }
    return matrix[1][num];
}
unique_ptr<Tree<int>> MCMSolver::getSolution(int i, int j)
{
    if(i==j)
        return make_unique<Tree<int>>(i);

    unique_ptr<Tree<int>> root = make_unique<Tree<int>>(0);
    root->setLeft(getSolution(i,infoMatrix[i][j]));
    root->setRight(getSolution(infoMatrix[i][j]+1,j));

    return root;
}
void MCMSolver::printSolution()
{
    unique_ptr<Tree<int>> root = getSolution(1,num);
    printFunc(root.get());
}
void printFunc(const Tree<int>* root)
{
    if(root==nullptr)
        return;
    if(root->getData()==0)
        cout << "(";

    printFunc(root->getLeft());

    if(root->getLeft()==nullptr&&root->getRight()==nullptr)
        cout << " " << root->getData() << " ";

    printFunc(root->getRight());

    if(root->getData()==0)
        cout << ")";
}
void testMCMSolver(int p[],int size)
{
    setlocale(LC_ALL,"");
    MCMSolver solver(p,size);
    for(int i=0;i<size;i++)
        cout << p[i] << (i<size-1?" ":"\n");
    wcout << "矩阵链乘所需的最小标量乘法数为：" << solver.getMaxMULNum() << "\n";
    solver.printSolution();
    cout << "\n";
}

