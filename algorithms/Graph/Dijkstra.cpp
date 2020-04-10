#include<iostream>
#include"../../graph/Graph.h"

using namespace std;
//在不在最小距离的顶点集合中 找最小值的顶点编号
int getMinIndex(vector<int>& dis,vector<bool> flag)
{
    int min=__INT_MAX__;//trick
    int pos = 0;//一定会在每次循环中找到最小值，初值不重要
    for(int i=0;i<dis.size();i++)
    {
        if(!flag[i]&&dis[i]<min)//flag为false的元素中的最小值
        {
            min = dis[i];
            pos = i;
        }
    }
    return pos;
}
vector<int> getShortestDis(Graph& g,int s=0)
{
    int v_num=g.getVnum();
    //距离向量
    vector<int> dis(v_num);
    dis[s] = 0;//源点距离为0
    //初始化为边的权重
    for(int i=0;i<v_num;i++)
        dis[i] = g.getWeight(s,i);
    //标记各点是否已为最小距离
    vector<bool> flag(v_num);
    for(bool f:flag)
        f = false;
    flag[s] = true;//源点初始为最小距离
    //第一次迭代
    for(int i=1;i<v_num;i++)
    {
        int node = getMinIndex(dis,flag);
        flag[node] = true;

        for(int i=0;i<v_num;i++)
        {
            //不为最小距离节点&&存在从node到i的边（短路计算，防止INT_MAX加法溢出
            if(!flag[i]&&g.existsEdge(node,i)&&dis[i]>dis[node]+g.getWeight(node,i))
            {
                dis[i] = dis[node]+g.getWeight(node,i);
            }
        }
    }

    return dis;
}

int main()
{
    Graph g(5);
    g.insertEdge(0,1,10);
    g.insertEdge(0,2,3);
    g.insertEdge(1,2,1);
    g.insertEdge(1,3,2);
    g.insertEdge(2,1,4);
    g.insertEdge(2,3,8);
    g.insertEdge(2,4,2);
    g.insertEdge(3,4,7);
    g.insertEdge(4,3,9);

    vector<int> dis = getShortestDis(g,0);

    for(int x:dis)
        cout << x << " ";
    cout << "\n";
    return 0;
}