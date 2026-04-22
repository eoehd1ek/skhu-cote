#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll INF = 987'654'321;

bool is_all_digits(const vector<string>& arr) {
    for (const string& s : arr) {
        for (char c : s) {
            if (!isdigit(c)) {
                return false;
            }
        }
    }
    return true;
}

bool is_not_all_digits(const vector<string>& arr) {
    return !is_all_digits(arr);
}

bool is_start_zero(const vector<string>& arr) {
    for (const string& s : arr) {
        if (s.front() == '0') {
            return true;
        }
    }
    return false;
}

vector<ll> string2longlong(const vector<string>& arr) {
    vector<ll> result;
    for (const string& s : arr) {
        result.push_back(stoll(s));
    }
    return result;
}

bool is_prime(ll n) {
    if (n <= 1) return false;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

bool is_not_prime(ll n) {
    return !is_prime(n);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    vector<string> tokens;
    // 입력
    while (getline(cin, s)) {
        stringstream ss(s);
        string token;
        while (ss >> token) {
            tokens.push_back(token);
        }
    }

    // 3개의 토큰이 아닌 경우 wa
    if (tokens.size() != 3) {
        cout << 0;
        return 0;
    }

    // 모두 숫자가 아닌 경우 wa
    if (is_not_all_digits(tokens)) {
        cout << 0;
        return 0;
    }

    // 0으로 시작하는 잘못된 숫자인 경우 wa (ex: 02, 0)
    if (is_start_zero(tokens)) {
        cout << 0;
        return 0;
    }

    // arr[0] != arr[1] + arr[2]인 경우 wa
    vector<ll> numbers = string2longlong(tokens);
    if (numbers[0] != numbers[1] + numbers[2]) {
        cout << 0;
        return 0;
    }

    // arr[0]이 짝수가 아닌 경우 wa
    if (numbers[0] % 2 != 0) {
        cout << 0;
        return 0;
    }

    // arr[0]이 3~1e9 범위가 아닌 경우 wa
    if (numbers[0] < 3 || numbers[0] > 1'000'000'000) {
        cout << 0;
        return 0;
    }

    // arr[1], arr[2]가 소수가 아닌 경우 wa
    if (is_not_prime(numbers[1]) || is_not_prime(numbers[2])) {
        cout << 0;
        return 0;
    }

    cout << 1;

    return 0;
}
