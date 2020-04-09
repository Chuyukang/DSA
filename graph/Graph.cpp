#include<vector>
#include"Graph.h"

using namespace std;

Graph::Graph() { v_num=0; }

Graph::Graph(int _v_num)
{
    v_num = _v_num;

    for(int i=0;i<v_num;i++)
        adjMatrix.push_back(vector<int>(v_num));

    for(int i=0;i<v_num;i++)
        for(int j=0;j<v_num;j++)
        {
            if(i==j)
                adjMatrix[i][j] = 0;
            else
                adjMatrix[i][j] = __INT_MAX__;//trick

        }
}

Graph::Graph(vector<vector<int> >& temp):adjMatrix(temp)
{ v_num = adjMatrix.size(); }

Graph::~Graph() { }

void Graph::insertEdge(int u,int v,int weight)
{ adjMatrix[u][v] = weight; }

int Graph::getWeight(int u,int v)
{
    return adjMatrix[u][v];
}
int Graph::getVnum()
{
    return v_num;
}
bool Graph::existsEdge(int u,int v)
{
    return adjMatrix[u][v]<__INT_MAX__ ;
}