//
// Created by Chu on 2020/4/11.
//
#include <iostream>
#include <vector>
#include "ds/Graph.h"

using namespace std;

typedef vector<vector<int> > adjMatrix;
extern vector<int> Dijkstra(Graph& g,int s=0);
extern bool BellmanFord_N(Graph& g,int s,vector<int>& dis);
//test
void print(const adjMatrix& adj);

adjMatrix getShortestDis(adjMatrix& adj)
{
   Graph g(adj);
   //扩展图
   g.insertNode();//默认增加新顶点到每个顶点的权为0的边，其他顶点到该顶点无边

   int v_num = g.getVnum();//增加顶点后，顶点数会改变
   //计算新顶点(v_num-1)到各边的最小距离
    vector<int> dis(v_num);
   if(!BellmanFord_N(g,v_num-1,dis))
   {
       cout << "There exists a negative cycle in the graph!\n";
       exit(1);
   }
   //test
//   for(auto i: dis)
//       cout << i << " ";
//   cout << "\n";
   //新建图，去掉最后新加的顶点，并改变权重
   Graph tempG = g;
   tempG.popNode();
   //去掉新加顶点，顶点数会改变
   v_num = tempG.getVnum();
   for(int u=0;u<v_num;u++)
   {
       for(int v=0;v<v_num;v++)
       {
           if(tempG.existsEdge(u,v))
                tempG.setWeight(u,v,tempG.getWeight(u,v)+dis[u]-dis[v]);
       }
   }
   //test
//   print(tempG.getadjMatrix());
//   cout << "\n";
   vector<vector<int>> allPairsDis;
    //使用Dijkstra算法计算各个点的最短路
   for(int i=0;i<v_num;i++)
   {
        vector<int> singleSource = Dijkstra(tempG,i);
        allPairsDis.push_back(singleSource);
   }
   //还原为原图上的距离
   for(int i=0;i<v_num;i++)
   {
       for(int j=0;j<v_num;j++)
       {
           if(allPairsDis[i][j]<__INT_MAX__)
                allPairsDis[i][j] -= dis[i] - dis[j];
       }
   }
   return allPairsDis;
}
