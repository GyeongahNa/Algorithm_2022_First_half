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

int N;
int en, cnt;
int lc[100005];
int rc[100005];
int p[100005];
vector<bool> visited(100005);

void getTree() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int p, c1, c2;
        scanf("%d %d %d", &p, &c1, &c2);
        if (c1 != -1) lc[p] = c1;
        if (c2 != -1) rc[p] = c2;
    }
}

void dfs(int node) {

    if (lc[node]) {
        p[lc[node]] = node;
        dfs(lc[node]);
    }
    if (rc[node]) {
        p[rc[node]] = node;
        dfs(rc[node]);
    }
}

void inorder(int node) {

    if (lc[node]) inorder(lc[node]);
    en = node;
    if (rc[node]) inorder(rc[node]);

}

void similar_inorder(int node) {

    cnt++;
    visited[node] = true;
    if (lc[node] && !visited[lc[node]]) similar_inorder(lc[node]);
    else if (rc[node] && !visited[rc[node]]) similar_inorder(rc[node]);
    else if (node == en) return ;
    else if (p[node]) similar_inorder(p[node]);
}

int main() {

    getTree();
    dfs(1);
    inorder(1);
    similar_inorder(1);
    printf("%d", --cnt);
    return 0;
}