#include <iostream>
using namespace std;

int graph[100][100];
bool visited[100];
int n;

void dfs(int node) {
    visited[node] = true;

    cout << node << " ";

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int e;
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int start;
    cin >> start;

    dfs(start);

    return 0;
}
