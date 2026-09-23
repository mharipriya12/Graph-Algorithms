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

    int source;
    cin >> source;

    int dist[100];
    bool visited[100] = {false};

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }

    dist[source] = 0;

    for (int count = 0; count < n - 1; count++) {

        int minDistance = INF;
        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDistance) {
                minDistance = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] &&
                graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Shortest distances:\n";

    for (int i = 0; i < n; i++) {
        cout << source << " -> " << i << " = " << dist[i] << endl;
    }

    return 0;
}
