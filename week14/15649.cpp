#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll INF = 987'654'321;

int n, m;
vector<int> arr;
vector<bool> visited;

void print_arr() {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << "\n";
}

void dfs(int depth) {
    if (depth == m) {
        print_arr();
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (visited[i]) continue;

        arr[depth] = i;
        visited[i] = true;
        dfs(depth + 1);
        visited[i] = false;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    arr = vector<int>(m);
    visited = vector<bool>(n + 1);
    dfs(0);

    return 0;
}
