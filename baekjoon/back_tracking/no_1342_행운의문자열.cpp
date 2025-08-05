#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cnt = 0;
string s;
vector<bool> used;
vector<char> current;

bool check() {
    for (int i = 0; i < current.size() - 1; ++i) {
        if (current[i] == current[i + 1]) return false;
    }
    return true;
}

void backtrack() {
    if (current.size() == s.size()) {
        if (check()) cnt++;
        return;
    }

    for (int i = 0; i < s.size(); ++i) {
        if (used[i]) continue;
        if (i > 0 && s[i] == s[i - 1] && !used[i - 1]) continue;

        used[i] = true;
        current.push_back(s[i]);
        backtrack();
        current.pop_back();
        used[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    sort(s.begin(), s.end());
    used.assign(s.size(), false);
    backtrack();
    cout << cnt << '\n';
}


/// 중복 제거를 위해 우선은 정렬하고
// s[i] == s[i - 1]	현재 문자가 이전 문자와 같은 문자일 때 (중복 발생 가능성 존재)
// !used[i - 1]	이전 같은 문자를 아직 사용하지 않았다면, 이번 것도 사용하지 마라

// 걍 문자열 다 만들고 확인하는게 나음
