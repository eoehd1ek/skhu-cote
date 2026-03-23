#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll INF = 987'654'321;

struct Node {
    ll last_time, counter_id, uid;

    Node() : last_time(0), counter_id(0), uid(0) {}
    Node(ll t, ll c, ll u) : last_time(t), counter_id(c), uid(u) {}
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
        q.emplace(0, i, -1);
    }

    vector<Node> out_info;
    out_info.reserve(n);
    for (int i = 0; i < n; ++i) {
        ll uid, items;
        cin >> uid >> items;

        const Node node = q.top();
        ll out_time = node.last_time + items;
        q.pop();

        out_info.emplace_back(out_time, node.counter_id, uid);
        q.emplace(out_time, node.counter_id, uid);
    }

    sort(out_info.begin(), out_info.end(), out_compare);

    ll result = 0;
    for (ll i = 0; i < out_info.size(); ++i) {
        result += out_info[i].uid * (i + 1);
    }
    cout << result << "\n";

    return 0;
}
