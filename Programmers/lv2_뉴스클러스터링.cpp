#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second


void upper(string& s) {
    for (auto& c : s) {
        if (c >= 'a' && 'z' >= c) c = c-32;
    }
}


bool isupper(char c) {
    return c >= 'A' && 'Z' >= c;
}


vector<string> split(const string& s) {
    
    vector<string> v;
    int sz = s.size();
    for (int i=0; i<sz-1; i++) {
        //원소를 이루는 두 문자가 모두 대문자인 경우만 집합에 포함
        if (!isupper(s[i]) || !isupper(s[i+1])) continue;
        v.push_back(s.substr(i, 2));
    }
    return v;
}


double getScore(vector<string> v1, vector<string> v2) {
    
    if (!v1.size() && !v2.size()) return 1;
    
    double cnt = 0;
    double tot = v1.size()+v2.size();
    
    //v1와 v2에 모두 있는 원소를 v2에서 삭제하면서 교집합 구하기
    for (auto x : v1) {
        auto it = find(v2.begin(), v2.end(), x);
        if (it == v2.end()) continue;
        v2.erase(it);
        cnt++;
    }

    //교집합 수/(두 집합의 원소 합-교집합 수) 리턴
    return cnt/(tot-cnt);
}


int solution(string str1, string str2) {

    //문자열의 소문자를 대문자로 변경
    upper(str1); upper(str2);
    
    //각 문자열에서 나올 수 있는 집합 생성
    vector<string> v1 = split(str1);
    vector<string> v2 = split(str2);
    
    //J(str1, str2)*65536 리턴
    return getScore(v1, v2)*65536;
}