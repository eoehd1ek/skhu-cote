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

    int tc;
    cin >> tc;
    for (int cutc = 1; cutc <= tc; ++cutc) {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }

        sort(b.begin(), b.end());

        ll result = 0;
        for (int target : a) {
            auto it = upper_bound(b.begin(), b.end(), target);
            ll candidate_up = (it != b.end()) ? *it : 1e10;
            ll candidate_down = (it != b.begin()) ? *(prev(it)) : 1e10;

            ll up_diff = abs(candidate_up - target);
            ll down_diff = abs(candidate_down - target);

            if (up_diff < down_diff) {
                result += candidate_up;
            } else {
                result += candidate_down;
            }
        }

        cout << result << "\n";
    }

    return 0;
}
