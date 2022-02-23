#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second
#define str string

int cnt;
unordered_set<string> st, en;
char s[20], e[20], q[20], t[20], name[20];

int main() {

    scanf("%s %s %s", s, e, q);
    while (scanf("%s", t) != EOF) {
        scanf("%s", name);
        if (str(s) >= str(t)) st.insert(name);
        if (str(t) >= str(e) && str(q) >= str(t)) en.insert(name);
    }

    for (auto x : st) {
        if (en.find(x) != en.end()) cnt++;
    }
    printf("%d", cnt);
    return 0;
}