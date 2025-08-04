#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int> m;
    int n;
    cin >> n;

    int res = 0;
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        if (m.find(a) == m.end()) {
            if (b == 0) {
                res++;
            }
            m[a] = b;
            continue;
        }

        if (m[a] == b) {
            res++;
            continue;
        }
        m[a] = b;
    }

    for (auto &[k, v] : m) {
        if (v == 1) {
            res++;
        }
    }
    cout << res << '\n';
}