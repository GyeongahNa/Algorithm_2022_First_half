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
using ss = pair<string, string>;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

vector<string> solution(vector<string> record) {
    
    map<string, string> m;
    vector<ss> v;
    for (auto s : record) {
        stringstream in(s);
        string cmd, id, name;
        in >> cmd >> id;
        v.push_back({cmd, id});
        if (cmd == "Leave") continue;
        in >> name;
        m[id] = name;
    }
    
    vector<string> ret;
    for (auto [cmd, id] : v) {
        if (cmd == "Change") continue;
        if (cmd == "Enter") ret.push_back(m[id]+"님이 들어왔습니다.");
        else ret.push_back(m[id]+"님이 나갔습니다.");
    }
    
    return ret;
}