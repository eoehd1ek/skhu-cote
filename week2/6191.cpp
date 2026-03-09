#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll INF = 987'654'321;

int n, m;
vector<vector<char>> arr;
vector<vector<int>> visited;

vector<pair<int, int>> xy = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool able(int i, int j) {
    if (i < 1 || i > n || j < 1 || j > m) return false;
    return true;
}

void bfs(int start_i, int start_j) {
    queue<pair<int, int>> q;
    q.push({start_i, start_j});
    visited[start_i][start_j] = 0;

    while (!q.empty()) {
        auto [i, j] = q.front();
        int next_cost = visited[i][j] + 1;
        q.pop();

        for (const pair<int, int>& p : xy) {
            int ni = i + p.first;
            int nj = j + p.second;

            if (!able(ni, nj)) continue;
            if (arr[ni][nj] == '*') continue;
            if (visited[ni][nj] <= next_cost) continue;

            q.push({ni, nj});
            visited[ni][nj] = next_cost;
        }
    }
}

vector<pair<int, int>> get_path(int start_i, int start_j) {
    vector<pair<int, int>> result;
    queue<pair<int, int>> q;
    q.push({start_i, start_j});
    while (!q.empty()) {
        auto [i, j] = q.front();
        result.push_back({i, j});
        q.pop();

        int next_cost = visited[i][j] - 1;
        for (const pair<int, int>& p : xy) {
            int ni = i + p.first;
            int nj = j + p.second;

            if (!able(ni, nj)) continue;
            if (visited[ni][nj] != next_cost) continue;

            q.push({ni, nj});
            break;
        }
    }

    reverse(result.begin(), result.end());
    return result;
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
    arr = vector<vector<char>>(n + 2, vector<char>(m + 2, '*'));
    visited = vector<vector<int>>(n + 2, vector<int>(m + 2, INF));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
        }
    }

    bfs(1, 1);

    vector<pair<int, int>> result = get_path(n, m);
    for (const pair<int, int>& p : result) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
