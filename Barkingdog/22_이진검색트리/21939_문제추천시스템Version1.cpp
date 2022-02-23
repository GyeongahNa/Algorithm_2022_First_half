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

int N, M;
map<int, set<int>> level;
map<int, int> prob;

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int P, L;
        scanf("%d %d", &P, &L);
        level[L].insert(P);
        prob[P] = L;
    }
    
    scanf("%d", &M);
    for (int i=0; i<M; i++) {
        char cmd[20];
        scanf("%s", cmd);
        if (str(cmd) == "recommend") {
            int x;
            scanf("%d", &x);
            if (x == 1) printf("%d\n", *(prev((prev(level.end())->second).end())));
            else printf("%d\n", *((level.begin()->second).begin()));
        }   
        else if (str(cmd) == "add") {
            int P, L;
            scanf("%d %d", &P, &L);
            level[L].insert(P);
            prob[P] = L;
        }
        else if (str(cmd) == "solved") {
            int P;
            scanf("%d", &P);
            level[prob[P]].erase(P);
            if (!level[prob[P]].size()) level.erase(prob[P]);
            prob.erase(P);
        }
    }
    return 0;
}