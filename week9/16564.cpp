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

    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    ll l = 0;
    ll r = 2'000'000'001;
    ll result = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        ll cnt = 0;
        for (ll i : arr) {
            ll need = max(0ll, mid - i);
            cnt += need;
        }

        if (cnt <= k) {
            result = max(result, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << result << "\n";

    return 0;
}
