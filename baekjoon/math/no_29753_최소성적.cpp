#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    const vector<pair<string, int>> grade_tbl = {
        {"F",   0},  {"D0", 100}, {"D+", 150}, {"C0", 200}, {"C+", 250},
        {"B0", 300}, {"B+", 350}, {"A0", 400}, {"A+", 450}
    };
    unordered_map<string,int> to_score;
    for (auto &[g,s] : grade_tbl) to_score[g] = s;

    int N; double X;
    cin >> N >> X;

    long long cur_sum = 0;
    int cur_cred = 0;

    for (int i = 0; i < N - 1; ++i) {
        int c; string g;
        cin >> c >> g;
        cur_sum  += 1LL * c * to_score[g];
        cur_cred += c;
    }

    int L;
    cin >> L;
    int tot_cred = cur_cred + L;

    int X100 = int(X * 100 + 1e-6);
    long long target_sum = 1LL * (X100 + 1) * tot_cred;

    long long need = target_sum - cur_sum;
    long long goal = need <= 0 ? 0 : (need + L - 1) / L;

    string ans = "impossible";
    for (const auto &[g, s] : grade_tbl) {
        if (s >= goal) { ans = g; break; }
    }
    cout << ans << '\n';
    return 0;
}