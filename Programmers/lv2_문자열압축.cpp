#include <cstdio>
#include <cstring>
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
#include <sstream>
#include <string>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;


int ncompress(const string& s, int n) {
    
    int ret = 0, cnt = 1, sz = s.size();
    string bf = s.substr(0, n);
    
    for (int i=1; i<=sz/n; i++) {
        string tmp = s.substr(i*n, n);
        if (bf == tmp) {
            cnt++;
            continue;
        }
        if (cnt > 1) ret += to_string(cnt).size();
        ret += n;
        cnt = 1;
        bf = tmp;
    }
    
    ret += max(0, sz-sz/n*n);
    return ret;
}

int solution(string s) {
    
    int sz = s.size();
    int mn = sz;
    
    for (int i=1; i<=sz; i++)
        mn = min(mn, ncompress(s, i));
    
    return mn;
}