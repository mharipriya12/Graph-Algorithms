#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u;
    int v;
    int weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int parent[100];

int findParent(int node) {
    if (parent[node] == node)
        return node;

    return parent[node] = findParent(parent[node]);
}

void unionSet(int u, int v) {
    int parentU = findParent(u);
    int parentV = findParent(v);

    parent[parentU] = parentV;
}

int main() {
    int n, e;
    cin >> n >> e;

    Edge edges[100];

    for (int i = 0; i < e; i++) {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    sort(edges, edges + e, compare);

    int totalCost = 0;
    int count = 0;

    cout << "Edges in MST:\n";

    for (int i = 0; i < e; i++) {

        int u = edges[i].u;
        int v = edges[i].v;

        if (findParent(u) != findParent(v)) {

            cout << u << " - "
                 << v << " : "
                 << edges[i].weight << endl;

            totalCost += edges[i].weight;

            unionSet(u, v);

            count++;

            if (count == n - 1)
                break;
        }
    }

    cout << "Total Cost = "
         << totalCost << endl;

    return 0;
}
