#include<vector>

using namespace std;

class Graph
{
private:
    vector<vector<int> > adjMatrix;
    int v_num;
public:
    Graph();
    explicit Graph(int _v_num);
    explicit Graph(vector<vector<int> >& temp);
    ~Graph();
    void insertEdge(int u,int v,int weight);

    int getVnum();
    int getWeight(int u,int v);
    void setWeight(int u,int v,int weight);
    bool existsEdge(int u,int v);
    //在末尾添加和删除顶点
    void insertNode();
    void popNode();
    //test
    vector<vector<int>> getadjMatrix();
};
