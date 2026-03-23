#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll INF = 987'654'321;

// fastIO
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#include <cstdio>

constexpr int SZ = 1 << 20;

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
    // fastIO start
    struct stat st;
    fstat(0, &st);
    char* p = (char*)mmap(0, st.st_size, PROT_READ, MAP_SHARED, 0, 0);
    char w[SZ], *q = w;

    auto readInt = [&]() {
        int ret = 0;
        for (char c = *p++; c & 16; ret = (ret << 3) + (ret << 1) + (c & 15), c = *p++);  // ret * 10
        return ret;
    };
    auto readLL = [&]() {
        ll ret = 0;
        for (char c = *p++; c & 16; ret = (ret << 3) + (ret << 1) + (c & 15), c = *p++);  // ret * 10
        return ret;
    };
    auto readNegaInt = [&]() {
        int ret = 0;
        bool nega = false;
        if (*p == '-') {
            nega = true;
            ++p;
        }
        for (char c = *p++; c & 16; ret = (ret << 3) + (ret << 1) + (c & 15), c = *p++);  // ret * 10
        return nega ? -ret : ret;
    };
    auto readNegaLL = [&]() {
        ll ret = 0;
        bool nega = false;
        if (*p == '-') {
            nega = true;
            ++p;
        }
        for (char c = *p++; c & 16; ret = (ret << 3) + (ret << 1) + (c & 15), c = *p++);  // ret * 10
        return nega ? -ret : ret;
    };
    auto readString = [&]() {
        string ret;
        while (*p && *p <= 32) ++p;
        while (*p && *p > 32) {
            ret += *p++;
        }
        return ret;
    };
    auto readDouble = [&]() {
        string ret = readString();
        return stod(ret);
    };
    auto GetSize = [&](int n) {
        int sz = 1;
        for (; n >= 10; n /= 10) sz++;
        return sz;
    };
    auto GetLLSize = [&](ll n) {
        int sz = 1;
        for (; n >= 10; n /= 10) sz++;
        return sz;
    };
    auto flush = [&]() {
        write(1, w, q - w);
        q = w;
    };
    auto writeInt = [&](int n) {
        if (n < 0) *q++ = '-', n = -n;
        int sz = GetSize(n);
        if (q + sz - w >= SZ) flush();
        for (int i = sz; i-- > 0; n /= 10) q[i] = n % 10 | 48;
        q += sz;
    };
    auto writeLL = [&](ll n) {
        if (n < 0) *q++ = '-', n = -n;
        int sz = GetLLSize(n);
        if (q + sz - w >= SZ) flush();
        for (int i = sz; i-- > 0; n /= 10) q[i] = n % 10 | 48;
        q += sz;
    };
    auto writeString = [&](const string& s) {
        int len = s.size();
        if (q + len - w >= SZ) flush();
        for (char c : s) {
            *q++ = c;
        }
    };
    // fastIO end

    int n = readInt();
    int m = readInt();

    priority_queue<Node, vector<Node>, compare> pq;
    for (int i = 0; i < m; ++i) {
        pq.push({0, i, -1});
    }

    vector<Node> out_info;
    out_info.reserve(n);
    for (int i = 0; i < n; ++i) {
        ll uid = readLL();
        ll items = readLL();

        const Node node = pq.top();
        ll out_time = node.last_time + items;
        pq.pop();

        out_info.emplace_back(out_time, node.counter_id, uid);
        pq.emplace(out_time, node.counter_id, uid);
    }

    sort(out_info.begin(), out_info.end(), out_compare);

    ll result = 0;
    for (ll i = 0; i < out_info.size(); ++i) {
        result += out_info[i].uid * (i + 1);
    }
    writeLL(result);
    writeString("\n");

    flush();

    return 0;
}