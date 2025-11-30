#include <iostream>
#include <vector>
using namespace std;
class Graph {
    int V;
    vector<vector<int>> adj;
    void dfsUtil(int u, vector<bool>& visited){
        visited[u] = true;
        cout << u << " ";

        for(int v : adj[u]){
            if(!visited[v])
                dfsUtil(v, visited);
        }
    }
public:
    Graph(int V){
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    void DFS(int start){
        vector<bool> visited(V, false);
        cout << "DFS: ";
        dfsUtil(start, visited);
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    g.DFS(0);
    return 0;
}
