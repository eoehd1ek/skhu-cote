#include <bits/stdc++.h>

using namespace std;

bool compare(const string& a, const string& b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> arr;
    for (int i : numbers) {
        arr.push_back(to_string(i));
    }
    sort(arr.begin(), arr.end(), compare);

    string result;
    for (const string& s : arr) {
        result += s;
    }

    bool is_zero = true;
    for (char c : result) {
        if (c != '0') {
            is_zero = false;
            break;
        }
    }
    if (is_zero) return "0";

    return result;
}