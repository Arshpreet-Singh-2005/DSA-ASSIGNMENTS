#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Edge {
    int u, v, w;
};
bool cmp(Edge a, Edge b) { return a.w < b.w; }
int findParent(int v, vector<int>& parent) {
    if (parent[v] == v) return v;
    return parent[v] = findParent(parent[v], parent);
}
void kruskal(Edge edges[], int n, int e) {
    sort(edges, edges + e, cmp);
    vector<int> parent(n);
    for (int i = 0; i < n; i++) parent[i] = i;
    cout << "Edges in MST:\n";
    int cost = 0;
    for (int i = 0; i < e; i++) {
        int p1 = findParent(edges[i].u, parent);
        int p2 = findParent(edges[i].v, parent);

        if (p1 != p2) {
            cout << edges[i].u << " - " << edges[i].v << " : " << edges[i].w << endl;
            cost += edges[i].w;
            parent[p1] = p2;
        }
    }
    cout << "\nMinimum Weight = " << cost;
}
int main() {
    Edge edges[] = {{0,1,2},{0,3,6},{1,2,3},{1,3,8},{2,4,5},{3,4,9}};
    kruskal(edges, 5, 6);
    return 0;
}
