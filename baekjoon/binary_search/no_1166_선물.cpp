#include <iomanip>
# include <iostream>
# include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, l, w, h;
    cin >> n >> l >> w >> h;
    double ans = 0;
    double left = 0, right = min(h, min(l, w));

    for (int i = 0; i < 100; i++) {
        double mid = (left + right) / 2;
        long long cnt = ((long long) (l / mid)) * ((long long) (w / mid)) * ((long long) (h / mid));

        if (cnt >= n) {
            ans = mid;
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << fixed << setprecision(10) << ans << '\n';
}