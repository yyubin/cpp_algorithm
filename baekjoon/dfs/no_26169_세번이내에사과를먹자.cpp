#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int result = 0;
bool possible = false;

void dfs(int x, int y, int cnt, int apple, vector<vector<int>> &g) {
    if (possible) {
        return;
    }

    if (cnt > 3) {
        return;
    }

    if (apple >= 2) {
        possible = true;
        return;
    }

    for (auto &[dx, dy] : dir) {
        int nx = x + dx, ny = y + dy;
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || g[nx][ny] == -1) continue;
        int temp = g[nx][ny];
        int current_apple_eaten = 0;
        if (g[nx][ny] == 1) {
            current_apple_eaten = 1;
        }

        g[nx][ny] = -1;
        dfs(nx, ny, cnt+1, apple + current_apple_eaten, g);
        g[nx][ny] = temp;
    }

}

int main() {
    vector<vector<int>> g(5, vector<int>(5));
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            cin >> g[i][j];

    int x, y;
    cin >> x >> y;

    int apple = g[x][y] == 1 ? 1 : 0;
    g[x][y] = -1;
    dfs(x, y, 0, apple, g);

    cout << (possible ? 1 : 0) << '\n';
}