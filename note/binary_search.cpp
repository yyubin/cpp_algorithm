#include <iostream>
#include <vector>
using namespace std;

bool condition(int mid) {
    // 예: mid로 뭔가가 가능한지 판단
    return mid >= 10;
}

int main() {
    int low = 1, high = 1000000;
    int answer = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (condition(mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << '\n';
}
