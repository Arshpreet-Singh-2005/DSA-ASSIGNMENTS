#include <iostream>
using namespace std;
#define INF 1000
#define V 5
int minDistance(int dist[], bool visited[]) {
    int min = INF, idx = -1;
    for (int i = 0; i < V; i++)
        if (!visited[i] && dist[i] <= min) { min = dist[i]; idx = i; }
    return idx;
}
void dijkstra(int graph[V][V], int start) {
    int dist[V];
    bool visited[V] = {0};
    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[start] = 0;
for (int count = 0; count < V-1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;
        for (int v = 0; v < V; v++){
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "Shortest distances from source " << start << ":\n";
    for (int i = 0; i < V; i++){
        cout << i << " : " << dist[i] << endl;
    }
}
int main() {
    int graph[V][V] = {
        {0,10,0,0,5},{10,0,1,0,2},{0,1,0,4,0},{0,0,4,0,3},{5,2,0,3,0}
    };
    dijkstra(graph, 0);
    return 0;
}

