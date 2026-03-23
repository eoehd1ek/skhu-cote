#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll INF = 987'654'321;

struct Node {
    ll last_time, counter_id, uid;
};

struct compare {
    bool operator()(const Node& a, const Node& b) {
        if (a.last_time != b.last_time) {
            return a.last_time > b.last_time;
        }
        return a.counter_id > b.counter_id;
    }
};

bool out_compare(const Node& a, const Node& b) {
    if (a.last_time != b.last_time) {
        return a.last_time < b.last_time;
    }
    return a.counter_id > b.counter_id;
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

    priority_queue<Node, vector<Node>, compare> q;
    for (int i = 0; i < m; ++i) {
        q.push({0, i, -1});
    }

    // uid
    vector<Node> out_info;
    for (int i = 0; i < n; ++i) {
        ll uid, items;
        cin >> uid >> items;

        ll top = q.top().last_time;
        ll counter_id = q.top().counter_id;
        ll prev_uid = q.top().uid;
        q.pop();

        ll out_time = top + items;
        out_info.push_back({out_time, counter_id, uid});
        q.push({out_time, counter_id, uid});
    }

    sort(out_info.begin(), out_info.end(), out_compare);

    ll result = 0;
    for (ll i = 0; i < out_info.size(); ++i) {
        result += out_info[i].uid * (i + 1);
    }
    cout << result << "\n";

    return 0;
}
