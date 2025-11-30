#include <iostream>
#include <vector>
using namespace std;
class Graph {
    int V;
    vector<vector<int>> adj;
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    int degree(int v){
        return adj[v].size();
    }
    void adjacentVertices(int v){
        cout << "Adjacent to " << v << ": ";
        for(int u: adj[v]) cout << u << " ";
        cout << endl;
    }
    int numberOfEdges(){
        int cnt = 0;
        for(int i=0;i<V;i++) cnt += adj[i].size();
        return cnt/2;
    }
};
int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(3,4);
    cout << "Degree of vertex 1 = " << g.degree(1) << endl;
    g.adjacentVertices(0);
    cout << "Total edges = " << g.numberOfEdges() << endl;
    return 0;
}