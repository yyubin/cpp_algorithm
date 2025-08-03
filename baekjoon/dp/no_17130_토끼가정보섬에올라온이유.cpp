#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto &s: g) cin >> s;

    const int INF = -1;
    vector<vector<int> > dp(n, vector<int>(m, INF));

    int sr = 0, sc = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (g[i][j] == 'R') {
                sr = i;
                sc = j;
            }

    dp[sr][sc] = 0;

    auto in = [&](int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; };

    for (int j = sc + 1; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (g[i][j] == '#') continue;

            int best = INF;
            for (int d = -1; d <= 1; ++d) {
                int pi = i + d, pj = j - 1;
                if (in(pi, pj)) {
                    best = max(best, dp[pi][pj]);
                }
            }
            if (best == INF) continue;
            dp[i][j] = best + (g[i][j] == 'C');
        }
    }

    int ans = -1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (g[i][j] == 'O')
                ans = max(ans, dp[i][j]);

    cout << ans << '\n';
}


// 원래 O 기준으로 dp 돌려서 도달 가능한 당근 개수세고
// 해당 위치로 토끼가 나갈 수 있냐 -> bfs로 해결했었는데

// 그 당근 위치로 토끼가 나오기가 불가능할 수 있음
// 해당 사례 반례 :
//
// 2 5
// ROCCO
// CCOOC

// 그래서 걍 dp를 토끼 + 당근 전부 고려해야함
// 토끼 기준으로 [0][0]으로 만들어서 초기화 -> 토끼 이전 루트의 당근들은 가질 수 없어서
// for 문도 토끼 기준으로
// 열부터 순회 -> DP 식이 이전 의 값만 필요로 하기 때문에, 만약 행부터 순회하면 고려할 수 없는 케이스 생김
// 걍 위상적으로 열부터 생각해야함
// 위 중간 아래 중 최고를 골라서 진행 해당 위치에 당근이 있으면 + 1
//