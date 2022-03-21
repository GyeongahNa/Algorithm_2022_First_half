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
#include <numeric>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second


int solution(string s) {
    
    vector<int> v;
    
    int num = 0;
    for (auto c : s) {
        if ('0' <= c && c <= '9') num = num*10+c-'0'; //숫자계산
        else if (c == 'S') {v.push_back(num); num = 0;} //기본 숫자 추가
        else if (c == 'D') {v.push_back(num*num); num = 0;} //숫자를 제곱하여 추가
        else if (c == 'T') {v.push_back(num*num*num); num = 0;} //숫자를 세제곱하여 추가
        else if (c == '*') { //가장 최근의 두 점수에 x2
            int sz = v.size();
            v[sz-1] *= 2;
            if (sz >= 2) v[sz-2] *= 2;
        }
        else if (c == '#') v.back() *= -1; //가장 최근의 점수 마이너스로 변환
    }
    
    return accumulate(v.begin(), v.end(), 0);
}