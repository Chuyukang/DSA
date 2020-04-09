#include<vector>

using namespace std;

class Graph
{
private:
    vector<vector<int> > adjMatrix;
    int v_num;
public:
    Graph();
    Graph(int _v_num);
    Graph(vector<vector<int> >& temp);
    ~Graph();
    void insertEdge(int u,int v,int weight);

    int getVnum();
    int getWeight(int u,int v);
    bool existsEdge(int u,int v);
};
