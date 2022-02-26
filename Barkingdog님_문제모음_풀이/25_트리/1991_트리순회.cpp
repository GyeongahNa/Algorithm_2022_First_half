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

int N;
int lc[30], rc[30];

void preorder(int node) {

    printf("%c", node-1+'A');
    if (lc[node]) preorder(lc[node]);
    if (rc[node]) preorder(rc[node]);
}

void inorder(int node) {

    if (lc[node]) inorder(lc[node]);
    printf("%c", node-1+'A');
    if (rc[node]) inorder(rc[node]);
}

void postorder(int node) {

    if (lc[node]) postorder(lc[node]);
    if (rc[node]) postorder(rc[node]);
    printf("%c", node-1+'A');
}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        char n, c1, c2;
        scanf(" %c %c %c", &n, &c1, &c2);
        if (c1 != '.') lc[n-'A'+1] = c1-'A'+1;
        if (c2 != '.') rc[n-'A'+1] = c2-'A'+1;
    }

    preorder(1); 
    printf("\n");
    inorder(1); 
    printf("\n");
    postorder(1);
    return 0;
}