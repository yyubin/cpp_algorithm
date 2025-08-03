#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> visited;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        cout << "Visited: " << cur << '\n';

        for (int next : graph[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
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
        graph[v].push_back(u);  // 무방향 그래프
    }

    bfs(1);
}
