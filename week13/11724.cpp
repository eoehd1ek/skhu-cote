#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll INF = 987'654'321;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int current) {
    visited[current] = true;
    for (int next : adj[current]) {
        if (visited[next]) continue;
        dfs(next);
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

    int n, m;
    cin >> n >> m;

    adj = vector<vector<int>>(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int result = 0;
    visited = vector<bool>(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (visited[i]) continue;
        result += 1;
        dfs(i);
    }
    cout << result << "\n";

    return 0;
}
