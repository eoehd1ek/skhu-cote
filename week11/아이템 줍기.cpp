#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll INF = 987'654'321;

vector<pair<int, int>> xy = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<pair<int, int>> xyd = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

struct Node {
    int i, j, cost;
};

bool able(int i, int j, const vector<vector<int>>& arr) {
    if (arr[i][j] == 0) return false;

    // 외곽에 0이 있어야 함.
    for (const pair<int, int>& p : xyd) {
        int ni = i + p.first;
        int nj = j + p.second;

        if (arr[ni][nj] == 0) return true;
    }
    return false;
}

void print(const vector<vector<int>>& arr) {
    for (const vector<int>& v : arr) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    // 외곽선 채우기
    const int N = 102 * 2;
    vector<vector<int>> arr(N, vector<int>(N, 0));
    for (const vector<int>& ract : rectangle) {
        int lx = ract[0] * 2;
        int ly = ract[1] * 2;
        int rx = ract[2] * 2;
        int ry = ract[3] * 2;

        for (int i = ly; i <= ry; ++i) {
            for (int j = lx; j <= rx; ++j) {
                arr[i][j] = 1;
            }
        }
    }

    vector<vector<int>> visited(N, vector<int>(N, INF));
    queue<Node> q;
    q.push({characterY * 2, characterX * 2, 0});
    visited[characterY * 2][characterX * 2] = 0;

    while (!q.empty()) {
        auto [current_i, current_j, cost] = q.front();
        const int next_cost = cost + 1;
        q.pop();

        for (const pair<int, int>& p : xy) {
            int ni = current_i + p.first;
            int nj = current_j + p.second;

            if (able(ni, nj, arr) && visited[ni][nj] > next_cost) {
                visited[ni][nj] = next_cost;
                q.push({ni, nj, next_cost});
            }
        }
    }

    // print(arr);

    int result = visited[itemY * 2][itemX * 2] / 2;
    return result;
}
