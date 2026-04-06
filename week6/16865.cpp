#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll INF = 987'654'321;

vector<int> arr;

bool up_left(int current, int prev, int left) {
    if (left == 0) {
        return true;
    }

    if (current < 0) {
        return false;
    }

    if (arr[prev] <= arr[current]) {
        return false;
    }

    return up_left(current - 1, current, left - 1);
}

bool up_right(int current, int prev, int left) {
    if (left == 0) {
        return true;
    }

    if (current >= arr.size()) {
        return false;
    }

    if (arr[prev] <= arr[current]) {
        return false;
    }
    return up_right(current + 1, current, left - 1);
}

bool up_check(int current, int left) {
    return up_left(current - 1, current, left) && up_right(current + 1, current, left);
}

bool down_left(int current, int prev, int left) {
    if (left == 0) {
        return true;
    }

    if (current < 0) {
        return false;
    }

    if (arr[prev] >= arr[current]) {
        return false;
    }

    return down_left(current - 1, current, left - 1);
}

bool down_right(int current, int prev, int left) {
    if (left == 0) {
        return true;
    }

    if (current >= arr.size()) {
        return false;
    }

    if (arr[prev] >= arr[current]) {
        return false;
    }
    return down_right(current + 1, current, left - 1);
}

bool down_check(int current, int left) {
    return down_left(current - 1, current, left) && down_right(current + 1, current, left);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, up, down;
    cin >> n >> up >> down;
    arr = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result_up = 0;
    int result_down = 0;
    for (int i = 0; i < n; ++i) {
        if (up_check(i, up - 1)) {
            result_up += 1;
        }
        if (down_check(i, down - 1)) {
            result_down += 1;
        }
    }

    cout << result_up << " " << result_down << "\n";

    return 0;
}
