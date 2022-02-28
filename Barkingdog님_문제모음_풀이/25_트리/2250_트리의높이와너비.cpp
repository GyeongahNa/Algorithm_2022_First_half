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
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, root;
int col = 1;
int lc[10005];
int rc[10005];
int cnt[10005]; 
int mn[10005]; //level 별 가장 왼쪽 위치
int mx[10005]; //level 별 가장 오른쪽 위치

void setGraph() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int p, c1, c2;
        scanf("%d %d %d", &p, &c1, &c2);
        if (c1 != -1) lc[p] = c1;
        if (c2 != -1) rc[p] = c2;
        cnt[p]++; cnt[c1]++; cnt[c2]++;
    }

    for (int i=1; i<=N; i++) {
        if (cnt[i] == 1) root = i; //루트 노드
        mn[i] = INT_MAX;
    }
    
}

void dfs(int node, int lv) {

    if (lc[node]) dfs(lc[node], lv+1);

    mn[lv] = min(mn[lv], col);
    mx[lv] = max(mx[lv], col++);

    if (rc[node]) dfs(rc[node], lv+1);
}

int main() {

    setGraph();
    dfs(root, 1);

    int mxval = -1, mxlv = -1;
    for (int i=1; i<=N; i++) {
        int width = mx[i]-mn[i]+1;
        if (width > mxval) {
            mxval = width;
            mxlv = i;
        }
    }
    printf("%d %d", mxlv, mxval);
    return 0;
}

/*
중위순회로 노드의 열(column) 구하기
*/