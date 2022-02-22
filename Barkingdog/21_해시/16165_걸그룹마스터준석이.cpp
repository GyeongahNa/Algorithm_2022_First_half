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

int N, M;
map<string, set<string>> team;
map<string, string> mem;

int main() {

    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        char tn[105];
        int num;
        scanf("%s", tn);
        scanf("%d", &num);
        for (int j=0; j<num; j++) {
            char mn[105];
            scanf("%s", mn);
            team[tn].insert(mn);
            mem[mn] = tn;
        }
    }
    for (int i=0; i<M; i++) {
        char qz[105];
        int num;
        scanf("%s", qz);
        scanf("%d", &num);
        if (!num) for (auto x : team[qz]) printf("%s\n", x.c_str());
        else printf("%s\n", mem[qz].c_str());
    }
    return 0;
}