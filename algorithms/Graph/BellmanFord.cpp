#include<iostream>
#include<vector>
#include"../../graph/Graph.h"

using namespace std;
//单源最短路，Bellman-Ford算法
vector<int> getShortestDis(Graph& g,int s=0)
{
    int v_num = g.getVnum();
    vector<int> dis(v_num);
    for(int i=0;i<v_num;i++)
        dis[i] = __INT_MAX__;//trick

    dis[s] = 0;
    //最多遍历V次
    for(int i=0;i<v_num;i++)
    {
        //简陋的遍历边
        for(int u=0;u<v_num;u++)
        {
            for(int v=0;v<v_num;v++)
            {
                if(g.existsEdge(u,v))
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