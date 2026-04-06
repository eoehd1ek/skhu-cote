#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll INF = 987'654'321;

ll low, high;
const int n = 5;
vector<ll> arr(n);

bool check(ll sum) {
    return low <= sum && sum <= high;
}

bool dfs(int current, ll sum) {
    if (current == n) {
        return check(sum);
    }

    for (int i = current; i < n; ++i) {
        if (dfs(i + 1, sum + arr[i])) {
            return true;
        }
        if (dfs(i + 1, sum)) {
            return true;
        }
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while (tc-- > 0) {
        cin >> low >> high;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        string result = "NO";
        if (dfs(0, 0)) {
            result = "YES";
        }
        cout << result << "\n";
    }

    return 0;
}
