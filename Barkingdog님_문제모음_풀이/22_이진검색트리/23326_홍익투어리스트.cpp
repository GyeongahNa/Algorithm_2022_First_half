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
#include <iostream>

using namespace std;
using str = string;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, Q, pos;
map<int, int> area;
map<int, set<int>> landmark;

int main() {

    scanf("%d %d", &N, &Q);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        area[i] = x;
        landmark[x].insert(i);
    }

    for (int i=0; i<Q; i++) {
        int cmd;
        scanf("%d", &cmd);
        if (cmd == 1) {
            int i;
            scanf("%d", &i);
            landmark[area[i-1]].erase(i-1);
            landmark[!area[i-1]].insert(i-1);
            area[i-1] = !area[i-1];
        }
        else if (cmd == 2) {
            int x;
            scanf("%d", &x);
            pos = (pos+x)%N;
        }
        else if (cmd == 3) {
            if (!landmark[1].size()) {
                printf("-1\n");
                continue;
            }
            int dist = 0;
            auto nearest = landmark[1].lower_bound(pos);
            if (nearest == landmark[1].end()) dist = (N-pos)+*(landmark[1].begin());
            else dist = *nearest-pos;
            printf("%d\n", dist);
        }
    }
    return 0;
}