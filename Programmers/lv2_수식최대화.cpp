#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
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


vector<string> v = {"+-*", "+*-", "-+*", "-*+", "*-+", "*+-"};


bool isNum(char c) {
    return '0' <= c && c <= '9';
}


void split(deque<string>& dq, const string& s) {
    
    int i = 0;
    int sz = s.size();
    
    while (i < sz) {

        //숫자인 부분 분리
        if (isNum(s[i])) {
            string tmp = "";
            while (i < sz && isNum(s[i])) tmp += s[i++];
            dq.push_back(tmp);
            continue;
        }

        //+, -, * 기호 분리
        dq.push_back(string(1, s[i++]));
    }
}


string operate(long long n1, long long n2, string op) {
    
    if (op == "+") return to_string(n1+n2);
    if (op == "-") return to_string(n1-n2);
    return to_string(n1*n2);
}


void calc(deque<string>& tmp, string op) {
    
    deque<string> ret;
    
    while (!tmp.empty()) {
        
        string s = tmp.front();
        tmp.pop_front();
        
        //처리하고자 하는 연산자일 때 "계산하여" ret에 추가
        if (s == op) {
            long long n1 = stoll(ret.back());
            long long n2 = stoll(tmp.front());
            ret.pop_back();
            tmp.pop_front();
            ret.push_back(operate(n1, n2, op));
            continue;
        }

        //처리하고자 하는 연산자가 아닐 때 ret에 바로 추가
        ret.push_back(s);
    }
    
    tmp = ret;
}


long long solution(string expression) {
    
    //expression의 숫자들과 기호들을 분리하여 덱에 저장
    deque<string> dq;
    split(dq, expression);

    long long mx = 0;
    for (auto comb : v) {

        //우선순위 조합 comb를 순서대로 적용했을 때의 결과를 tmp에 저장
        deque<string> tmp = dq;
        for (auto op : comb) calc(tmp, string(1, op));
        mx = max(mx, abs(stoll(tmp.front())));
    }
    
    return mx;
}