#include<iostream>
#include<vector>
#include"../../graph/Graph.h"

using namespace std;
//单源最短路，Bellman-Ford算法
vector<int> BellmanFord(Graph& g,int s=0)
{
    int v_num = g.getVnum();
    vector<int> dis(v_num);
    //初始不存在从源点到各个顶点的路径
    for(int i=0;i<v_num;i++)
        dis[i] = __INT_MAX__;//trick

    dis[s] = 0;
    //最多遍历V-1次
    for(int i=1;i<v_num;i++)
    {
        //简陋的遍历边
        for(int u=0;u<v_num;u++)
        {
            for(int v=0;v<v_num;v++)
            {
                //u,v边存在 且 存在从s到u的路径
                if(g.existsEdge(u,v)&&dis[u]<__INT_MAX__)
                {
                    int temp=dis[u]+g.getWeight(u,v);
                    if(dis[v]>temp)//松弛步
                        dis[v] = temp;
                }
            }
        }
    }
    return dis;
}
bool BellmanFord_N(Graph& g,int s,vector<int>& dis)
{
    int v_num = g.getVnum();
    for(int i=0;i<v_num;i++)
        dis[i] = __INT_MAX__;//trick

    dis[s] = 0;
    //最多遍历V-1次
    for(int i=1;i<v_num;i++)
    {
        //简陋的遍历边
        for(int u=0;u<v_num;u++)
        {
            for(int v=0;v<v_num;v++)
            {
                //u,v边存在 且 存在从s到u的路径
                if(g.existsEdge(u,v)&&dis[u]<__INT_MAX__)
                {
                    int temp=dis[u]+g.getWeight(u,v);
                    if(dis[v]>temp)//松弛步
                        dis[v] = temp;
                }
            }
        }
    }
    //若最短路径不收敛，则有负权重回路
    for(int u=0;u<v_num;u++)
    {
        for(int v=0;v<v_num;v++)
        {
            if(g.existsEdge(u,v)&&dis[u]<__INT_MAX__)
            {
                int temp=dis[u]+g.getWeight(u,v);
                if(dis[v]>temp)
                    return false;
            }
        }
    }
    return true;
}

