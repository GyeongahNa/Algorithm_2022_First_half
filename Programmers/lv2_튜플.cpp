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

int cnt[100005];

void cntNum(const string& s) {
    
    string tmp = "";
    for (auto c : s) {
        if ('0' <= c && c <= '9') {
            tmp += c;
            continue;
        }
        if (tmp == "") continue;
        cnt[stoi(tmp)]++;
        tmp = "";
    }
    
}

vector<int> solution(string s) {

    //문자열에 등장한 숫자 카운트
    cntNum(s);
    
    //{등장횟수, 수} 벡터에 저장
    vector<ii> v;
    for (int i=1; i<=100000; i++) {
        if (!cnt[i]) continue;
        v.push_back({cnt[i], i});
    }

    //등장횟수가 많은 순으로 정렬
    sort(v.begin(), v.end(), greater<>());
    
    vector<int> ret;
    for (auto [n, x] : v) ret.push_back(x);
    return ret;
}

/*
특정 수가 주어진 문자열에서 더 많이 등장했다는 것은 초기 집합에서의 우선순위가 높다는 것이다.
따라서 문자열에서 숫자들의 등장 횟수를 모두 카운트 한 뒤,
가장 높은 카운트를 가진 수부터 벡터에 추가하면 된다.
*/