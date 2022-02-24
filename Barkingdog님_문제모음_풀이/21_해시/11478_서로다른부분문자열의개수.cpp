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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using is = pair<int, string>;
using iii = tuple<int, int, int>;
using uom = unordered_map<string, int>;

#define X first
#define Y second

string str;
unordered_set<string> s;

int main() {
    
    char x[1005];
    scanf("%s", x);
    str = string(x);

    for (int i=1; i<=str.size(); i++) {
        for (int j=0; j<str.size(); j++) {
            string tmp = str.substr(j, i);
            if (tmp.size() < i) continue;
            s.insert(tmp);
        }
    }

    printf("%d", (int)s.size());
    return 0;
}