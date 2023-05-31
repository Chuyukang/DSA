//
// Created by Chu on 2020/4/11.
//
#include <iostream>
#include <vector>
#include "ds/Graph.h"

using namespace std;
typedef vector<vector<int> > adjMatrix;

extern adjMatrix getShortestDis(adjMatrix& adj);

//打印最短距离矩阵
void print(const adjMatrix& adj)
{
    for(const vector<int>& v:adj)//可减少拷贝构造
    {
        for(int i:v)
        {
            if(i<__INT_MAX__)
                cout << i <<" ";
            else
                cout << "x" << " ";
        }
        cout << "\n";
    }
}
int main()
{
    int v_num = 6;
    Graph g(v_num);
    //添加边
    g.insertEdge(0,4,-1);
    g.insertEdge(1,0,1);
    g.insertEdge(1,3,2);
    g.insertEdge(2,1,2 );
    g.insertEdge(2,5,-8);
    g.insertEdge(3,0,-4);
    g.insertEdge(3,4,3 );
    g.insertEdge(4,1,7 );
    g.insertEdge(5,1,5 );
    g.insertEdge(5,2,10);
    adjMatrix adj = g.getadjMatrix();
    //计算最短路径长度
    adjMatrix shortestPath = getShortestDis(adj);
    cout << "The adjMatrix of Graph:\n";
    print(adj);
    cout << "\n";
    cout << "The Shortest Path of All Pairs of Nodes:\n";
    print(shortestPath);
    return 0;
}

