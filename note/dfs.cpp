#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    cout << "Visited: " << node << '\n';

    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    cin >> n >> m;
    graph.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  // 무방향
    }

    dfs(1);
}
