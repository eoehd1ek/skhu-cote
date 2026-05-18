#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll INF = 987'654'321;

int solution(int N, vector<vector<int>> road, int K) {
    vector<vector<pair<int, int>>> adj(N + 1);
    for (const vector<int>& r : road) {
        adj[r[0]].push_back({r[1], r[2]});
        adj[r[1]].push_back({r[0], r[2]});
    }

    vector<int> visited(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> q;
    q.push({0, 1});
    visited[1] = 0;
    while (!q.empty()) {
        auto [cost, current] = q.top();
        q.pop();

        if (visited[current] < cost) continue;

        for (const pair<int, int>& p : adj[current]) {
            int next = p.first;
            int next_cost = cost + p.second;
            if (next_cost >= visited[next]) continue;

            q.push({next_cost, next});
            visited[next] = next_cost;
        }
    }

    int result = 0;
    for (int i : visited) {
        if (i <= K) result += 1;
    }
    return result;
}
