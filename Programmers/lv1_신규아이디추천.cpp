#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;


string solution(string new_id) {
    
    for (auto& c : new_id) if ('A' <= c && c <= 'Z') c = c+32;
    
    string ret = "";
    for (auto& c : new_id) {
        if ('a' <= c && c <= 'z' || '0' <= c && c <= '9' || strchr("-_.", c)) ret += c;
    }
    
    new_id = ret;
    ret.clear();
    
    for (auto& c : new_id) {
        if (!ret.empty() && ret.back() == '.' && c == '.') continue;
        ret += c;
    }
    
    if (ret.front() == '.') ret.erase(ret.begin());
    if (ret.back() == '.') ret.pop_back();
    
    if (ret.empty()) ret = "a";
    if (ret.size() >= 16) ret = ret.substr(0, 15);
    if (ret.back() == '.') ret.pop_back();
    while (ret.size() < 3) ret += ret.back();
    
    return ret;
}

/*
strchr(const char* str, int c): str 내에 c가 있으면 존재하는 곳의 포인터를, 없으면 null 포인터 반환
string STL: s.front(), s.back(), s.erase(), s.pop_back()
*/