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

int T;

int main() {

    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        uom m;
        while (n--) {
            char s1[25], s2[25];
            scanf("%s %s", s1, s2);
            m[string(s2)]++;
        }

        int cnt = 1;
        for (uom::iterator it=m.begin(); it!=m.end(); it++) 
            cnt *= ((it->second)+1);
        printf("%d\n", cnt-1);
    }
    return 0;
}