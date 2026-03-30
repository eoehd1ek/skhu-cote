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

    // 최대 그림 크기 5m(백만))
    // 같은 라인 2번 칠하면 롤백됨.
    // 따라서 홀수인 경우에만 한번 칠하면 됨.
    // 가로 상황에서 최대 5m번
    // 세로 상황에서 최대 5m번 칠하므로 최악의 경우 10m번 칠함. 1초에 1000m 이므로 시간 복잡도 문제 없음.
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;

    vector<int> row(n + 1);
    vector<int> col(m + 1);
    for (int i = 0; i < k; ++i) {
        char c;
        int line;
        cin >> c >> line;

        if (c == 'R') {
            row[line] += 1;
        } else {
            col[line] += 1;
        }
    }

    vector<vector<bool>> arr(n + 1, vector<bool>(m + 1));
    // ROW
    for (int i = 1; i <= n; ++i) {
        int cnt = row[i] % 2;
        if (cnt == 0) continue;

        for (int j = 1; j <= m; ++j) {
            arr[i][j] = !arr[i][j];
        }
    }

    // COL
    for (int j = 1; j <= m; ++j) {
        int cnt = col[j] % 2;
        if (cnt == 0) continue;

        for (int i = 1; i <= n; ++i) {
            arr[i][j] = !arr[i][j];
        }
    }

    int result = 0;
    for (int i = 1; i <= n; ++i) {
        result += accumulate(arr[i].begin(), arr[i].end(), 0);
    }
    cout << result << "\n";

    return 0;
}
