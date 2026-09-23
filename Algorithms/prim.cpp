#include <iostream>
using namespace std;

#define INF 99999

int main() {
    int n, e;
    cin >> n >> e;

    int graph[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u][v] = w;
        graph[v][u] = w;
    }

    bool selected[100] = {false};

    selected[0] = true;

    int totalCost = 0;

    cout << "Edges in MST:\n";

    for (int count = 0; count < n - 1; count++) {

        int minWeight = INF;
        int x = -1;
        int y = -1;

        for (int i = 0; i < n; i++) {

            if (selected[i]) {

                for (int j = 0; j < n; j++) {

                    if (!selected[j] &&
                        graph[i][j] < minWeight) {

                        minWeight = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if (x == -1)
            break;

        cout << x << " - " << y
             << " : " << minWeight << endl;

        totalCost += minWeight;

        selected[y] = true;
    }

    cout << "Total Cost = " << totalCost << endl;

    return 0;
}
