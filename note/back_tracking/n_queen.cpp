#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> col;
vector<int> rows(n);

bool is_promising(int row) {
    for (int i = 0; i < row; ++i) {
        if (col[i] == col[row] || abs(col[row] - col[i]) == abs(row-i)) {
            return false;
        }
    }
    return true;
}

int n_queens(int row) {
    if (row == n) {
        return 1;
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        col[row] = i;
        if (is_promising(row)) {
            count += n_queens(row + 1);
        }
    }
    return count;
}

int main() {
    int n; cin >> n;
    col.resize(n);
    int sol = n_queens(0);
    cout << sol << '\n';
}