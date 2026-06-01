#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll INF = 987'654'321;

int n;
int result = INF;
vector<vector<int>> score;
vector<bool> visited;

int calc_diff() {
    int start = 0;
    int link = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (visited[i] != visited[j]) continue;

            if (visited[i]) {
                start += score[i][j] + score[j][i];
            } else {
                link += score[i][j] + score[j][i];
            }
        }
    }
    return abs(start - link);
}

void dfs(int start, int depth) {
    if (depth == n / 2) {
        int diff = calc_diff();
        result = min(result, diff);
        return;
    }

    for (int i = start; i <= n; ++i) {
        if (visited[i]) continue;

        visited[i] = true;
        dfs(i + 1, depth + 1);
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

    cin >> n;
    visited = vector<bool>(n + 1);
    score = vector<vector<int>>(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> score[i][j];
        }
    }

    dfs(1, 0);
    cout << result << "\n";

    return 0;
}
