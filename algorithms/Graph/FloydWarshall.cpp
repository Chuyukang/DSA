#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int> > adjMatrix;

//打印最短距离矩阵
extern void print(const adjMatrix& adj);
//计算图中任意两点对之间的最短路径距离
adjMatrix getShortestDis(adjMatrix& adj)
{
    adjMatrix cMatrix = adj;
    int v_num=adj.size();
    //用第k个点松弛，状态迁移至c(k)
    for(int k=0;k<v_num;k++)
    {
        for(int i=0;i<v_num;i++)
        {
            for(int j=0;j<v_num;j++)
            {
                //若i,k间和k,j间有边
                if(cMatrix[i][k]<__INT_MAX__ && cMatrix[k][j]<__INT_MAX__)
                {
                    int temp = cMatrix[i][k] + cMatrix[k][j];
                    if(temp<cMatrix[i][j])//松弛步
                        cMatrix[i][j] = temp;
                }
            }
        }
//        print(cMatrix);
//        cout << "\n";
    }
    return cMatrix;
}
