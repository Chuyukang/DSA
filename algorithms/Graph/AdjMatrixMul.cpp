#include <iostream>
#include <vector>
#include <clocale>

using namespace std;

typedef vector<vector<int> > adjMatrix;
//经过一条边可得到的最短路
adjMatrix extendAdjMatrix(adjMatrix lMatrix, adjMatrix adj)
{
    int v_num = lMatrix.size();
    //对每个点进行遍历
    for(int i=0;i<v_num;i++)
    {
        for(int j=0;j<v_num;j++)
        {
            for(int k=0;k<v_num;k++)
            {
                if(adj[k][j] < __INT_MAX__ && lMatrix[i][k]<__INT_MAX__)//如果存在边(k,j)
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
//打印最短距离矩阵
void print(const adjMatrix& adj)
{
    for(const vector<int>& v:adj)//可减少拷贝构造
    {
        for(int i:v)
            cout << i <<" ";
        cout << "\n";
    }
}
int main()
{
    int v_num = 5;
    adjMatrix adj;
    //初始化
    for(int i=0;i<v_num;i++)
        adj.push_back(vector<int>(v_num));
    //默认不连通
    for(int i=0;i<v_num;i++)
        for(int j=0;j<v_num;j++)
            adj[i][j] = __INT_MAX__;
    //结点到自身的距离为0
    for(int i=0;i<v_num;i++)
        adj[i][i] = 0;
    //添加边
    adj[0][1] = 10;
    adj[0][2] = 3;
    adj[1][2] = 1;
    adj[1][3] = 2;
    adj[2][1] = 4;
    adj[2][3] = 8;
    adj[2][4] = 2;
    adj[3][4] = 7;
    adj[4][3] = 9;
    //计算最短路径长度
    adjMatrix shortestPath = getShortestDis(adj);

    setlocale(LC_ALL,"");
    wcout << "图的邻接矩阵：\n";
    print(adj);
    cout << "\n";//wcout不能正常输出"\n"
    wcout << "图的最短距离矩阵：\n";
    print(shortestPath);

    return 0;
}
