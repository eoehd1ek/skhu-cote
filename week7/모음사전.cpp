#include <bits/stdc++.h>

using namespace std;


string target;
int cnt = 0;
int result = 0;
const string aeiou = "AEIOU";

bool dfs(const string& s) {
    if(s.size() >=6) return false;
    
    cnt +=1;
    if(s == target) {
        result = cnt;
        return true;
    }
    
    for(char c: aeiou) {
        bool result = dfs(s + c);
        if(result) return true;
    }
    
    return false;
}


int solution(string word) {
    target = word;
    
    dfs("");    
    
    result -= 1;
    return result;
}
