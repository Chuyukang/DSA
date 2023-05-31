//
// Created by Chu on 2020/4/11.
//
#include <iostream>
#include <vector>
#include "ds/Graph.h"

using namespace std;

extern vector<int> Dijkstra(Graph& g,int s=0);
extern vector<int> BellmanFord(Graph& g,int s=0);
extern bool BellmanFord_N(Graph& g,int s,vector<int>& dis);

int main()
{
    Graph g(5);
    g.insertEdge(1,2,5);
    g.insertEdge(1,3,8);
    g.insertEdge(1,4,-4);
    g.insertEdge(3,2,-3);
    g.insertEdge(3,4,9);
    g.insertEdge(4,2,4);
    g.insertEdge(4,0,2);
    g.insertEdge(0,1,6);
    g.insertEdge(0,3,7);
    g.insertEdge(2,1,-2);
//    g.insertEdge(0,1,10);
//    g.insertEdge(0,2,3);
//    g.insertEdge(1,2,1);
//    g.insertEdge(1,3,2);
//    g.insertEdge(2,1,4);
//    g.insertEdge(2,3,8);
//    g.insertEdge(2,4,2);
//    g.insertEdge(3,4,7);
//    g.insertEdge(4,3,9);

    cout << "Dijkstra Algorithm:\n";
    vector<int> dis1 = Dijkstra(g,0);
    for(int x:dis1)
        cout << x << " ";
    cout << "\n";

    cout << "BellmanFord Algorithm:\n";
    vector<int> dis2 = BellmanFord(g,0);
    for(int x:dis2)
        cout << x << " ";
    cout << "\n";

    return 0;
}
