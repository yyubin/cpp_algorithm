#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    int left = 0, right = 0, sum = 0, ans = 1e9;

    while (right < n) {
        sum += arr[right++];

        while (sum >= s) {
            ans = min(ans, right - left);
            sum -= arr[left++];
        }
    }

    if (ans == 1e9) cout << 0;
    else cout << ans;
}
