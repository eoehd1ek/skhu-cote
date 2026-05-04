#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll INF = 987'654'321;

bool able(const string& a, const string& b) {
    int diff = 0;
    for (int i = 0; i < a.size(); ++i) {
        diff += (a[i] != b[i]);
    }
    if (diff == 1) {
        return true;
    }
    return false;
}

int solution(string begin, string target, vector<string> words) {
    int result = INF;
    set<string> visited;

    queue<pair<string, int>> q;
    q.push({begin, 0});
    visited.insert(begin);
    while (!q.empty()) {
        auto [current, depth] = q.front();
        const int next_depth = depth + 1;
        q.pop();

        if (current == target) {
            result = min(result, depth);
            break;
        }

        for (const string& next : words) {
            if (able(current, next)) {
                if (visited.find(next) == visited.end()) {
                    q.push({next, next_depth});
                    visited.insert(next);
                }
            }
        }
    }

    if (result == INF) {
        return 0;
    }
    return result;
}
