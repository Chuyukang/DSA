#include <vector>

using namespace std;

typedef vector<vector<int> > adjMatrix;
//经过adj邻接矩阵可得到的最短路
adjMatrix extendAdjMatrix(adjMatrix lMatrix, adjMatrix adj)
{
    int v_num = lMatrix.size();
    //对每个点进行遍历
    for(int i=0;i<v_num;i++)
    {
        for(int j=0;j<v_num;j++)
        {
            //尝试松弛
            for(int k=0;k<v_num;k++)
            {
                //如果存在边(k,j)，且i顶点到k顶点之间存在路径
                if(adj[k][j] < __INT_MAX__ && lMatrix[i][k]<__INT_MAX__)
                {
                    int temp = lMatrix[i][k] + adj[k][j];
                    if(temp < lMatrix[i][j])//松弛步
                        lMatrix[i][j]=temp;
                }
            }
        }
    }
    return lMatrix;
}
//普通n-2次乘法，计算到n-1完成即可
adjMatrix slowExtend(const adjMatrix& adj)
{
    int v_num=adj.size();

    adjMatrix lMatrix=adj;
    for(int i=1;i<v_num-1;i++)
        lMatrix = extendAdjMatrix(lMatrix, adj);
    return lMatrix;
}
//类似快速幂算法
adjMatrix fastExtend(adjMatrix adj)
{
    int v_num = adj.size();
    for(int i=1;i<v_num;i*=2)
        adj = extendAdjMatrix(adj,adj);
    return adj;
}
//计算图中任意两点对之间的最短路径距离
adjMatrix getShortestDis(const adjMatrix& adj)
{
    return fastExtend(adj);
}
