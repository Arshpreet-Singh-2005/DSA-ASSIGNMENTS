#include <iostream>
using namespace std;

#define INF 1000

int main() {
    int n = 5;
    int graph[5][5] = {
        {0,2,0,6,0},{2,0,3,8,5},{0,3,0,0,7},{6,8,0,0,9},{0,5,7,9,0}
    };

    int selected[5] = {0};
    selected[0] = 1;
    int edges = 0, total = 0;

    cout << "Edges in MST:\n";
    while (edges < n - 1) {
        int min = INF, x = 0, y = 0;
        for (int i = 0; i < n; i++)
            if (selected[i])
                for (int j = 0; j < n; j++)
                    if (!selected[j] && graph[i][j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i; y = j;
                    }
        cout << x << " - " << y << " : " << min << endl;
        total += min;
        selected[y] = 1;
        edges++;
    }
    cout << "\nMinimum Weight = " << total;
    return 0;
}
