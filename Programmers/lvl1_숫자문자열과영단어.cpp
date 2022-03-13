#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
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

int solution(string s) {

    map<string, string> m = {{"zero", "0"}, {"one", "1"}, {"two", "2"}, {"three", "3"}, {"four", "4"}, 
                             {"five", "5"}, {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"}};
    
    string ret = "";
    int sz = s.size();
    for (int i=0; i<sz; i++) {
        if (s[i] >= '0' && '9' >= s[i]) {
            ret += s[i];
            continue;
        }
        
        string tmp = "";
        while (i < sz && (s[i] < '0' || s[i] > '9')) {
            tmp += s[i++];
            if (m.find(tmp) == m.end()) continue;
            ret += m[tmp];
            break;
        }
        i--;
    }

    return stoi(ret);
}