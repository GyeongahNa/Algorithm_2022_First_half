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
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using str = string;

#define X first
#define Y second

int N, M;
map<int, ii> prob; 
map<int, set<int>> level; 
map<int, map<int, set<int>>> algo; 

void reco() {
    
    int G, x;
    scanf("%d %d", &G, &x);
    
    if (x == 1) printf("%d\n", *prev((prev(algo[G].end())->second).end()));
    else printf("%d\n", *((algo[G].begin()->second).begin()));
}

void reco2() {
    
    int x;
    scanf("%d", &x);

    if (x == 1) printf("%d\n", *prev((prev(level.end())->second).end()));
    else printf("%d\n", *((level.begin()->second).begin()));
}

void reco3() {

    int x, L;
    scanf("%d %d", &x, &L);

    auto pos = level.lower_bound(L);
    if (x == 1) {
        if (pos == level.end()) printf("-1\n");
        else printf("%d\n", *((pos->second).begin()));
    }
    else {
        if (pos == level.begin()) printf("-1\n");
        else printf("%d\n", *prev((prev(pos)->second).end()));
    }
}

void add() {
    
    int P, L, G;
    scanf("%d %d %d", &P, &L, &G);

    prob[P] = {L, G};
    level[L].insert(P);
    algo[G][L].insert(P);
}

void sol() {

    int P;
    scanf("%d", &P);

    int lv = prob[P].X;
    int al = prob[P].Y;

    level[lv].erase(P);
    if (!level[lv].size()) level.erase(lv);

    algo[al][lv].erase(P);
    if (!algo[al][lv].size()) algo[al].erase(lv);
    if (!algo[al].size()) algo.erase(al); 
}


int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int P, L, G;
        scanf("%d %d %d", &P, &L, &G);
        prob[P] = {L, G};
        level[L].insert(P);
        algo[G][L].insert(P);
    }

    scanf("%d", &M);
    for (int i=0; i<M; i++) {
        char cmd[20];
        scanf("%s", cmd);
        if (str(cmd) == "recommend") reco();
        else if (str(cmd) == "recommend2") reco2();
        else if (str(cmd) == "recommend3") reco3();
        else if (str(cmd) == "add") add();
        else if (str(cmd) == "solved") sol();
    }
    return 0;
}