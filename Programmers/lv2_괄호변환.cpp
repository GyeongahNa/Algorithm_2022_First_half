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
using ss = pair<string, string>;
using iii = tuple<int, int, int>;

#define X first
#define Y second


bool correct(string s) {
    
    stack<char> st;
    
    for (auto c : s) {
        if (c == '(') st.push('(');
        else if (c == ')' && !st.empty() && st.top() == '(') st.pop();
        else return false;
    }
    return true;
}


ss split(string w) {
    
    vector<int> cnt(2, 0);
    
    int i;
    for (i = 0; i<w.size(); i++) {
        if (w[i] == '(') cnt[0]++;
        else cnt[1]++;
        if (cnt[0] == cnt[1]) break;
    }
    
    //{u, v} 리턴
    return {w.substr(0, ++i), w.substr(i)};
}


string convert(string w) {
    
    if (w == "") return w;
    
    //w를 u와 v로 분리
    ss tmp = split(w);
    string u = tmp.X, v = tmp.Y;
    
    //분리된 u가 올바른 문자열일 때 v를 수정하고 결합하여 리턴
    if (correct(u)) return u+convert(v);
    
    //분리된 u가 올바른 문자열이 아닐 때 처리
    string ret = "("+convert(v)+")";
    u.erase(u.begin());
    u.pop_back();

    //u의 괄호 방향을 거꾸로 변경
    for (auto& c : u) {
        if (c == '(') c = ')';
        else c = '(';
    }
    
    return ret+u;
}


string solution(string p) {

    //p가 올바른 문자열일 경우 그대로 출력
    if (correct(p)) return p;

    //변환하여 출력
    return convert(p);
}