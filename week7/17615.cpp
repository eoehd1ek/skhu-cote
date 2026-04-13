#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll INF = 987'654'321;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int result = INF;
    // case R을 왼쪽으로
    int candidate = 0;
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if (flag) {
            if (s[i] == 'R') {
                candidate += 1;
            }
        } else {
            if (s[i] == 'B') {
                flag = true;
            }
        }
    }
    result = min(result, candidate);

    // case R을 오른쪽으로
    candidate = 0;
    flag = false;
    for (int i = n - 1; i >= 0; --i) {
        if (flag) {
            if (s[i] == 'R') {
                candidate += 1;
            }
        } else {
            if (s[i] == 'B') {
                flag = true;
            }
        }
    }
    result = min(result, candidate);

    // case B을 왼쪽으로
    candidate = 0;
    flag = false;
    for (int i = 0; i < n; ++i) {
        if (flag) {
            if (s[i] == 'B') {
                candidate += 1;
            }
        } else {
            if (s[i] == 'R') {
                flag = true;
            }
        }
    }
    result = min(result, candidate);

    // case B을 오른쪽으로
    candidate = 0;
    flag = false;
    for (int i = n - 1; i >= 0; --i) {
        if (flag) {
            if (s[i] == 'B') {
                candidate += 1;
            }
        } else {
            if (s[i] == 'R') {
                flag = true;
            }
        }
    }
    result = min(result, candidate);

    cout << result << "\n";

    return 0;
}
