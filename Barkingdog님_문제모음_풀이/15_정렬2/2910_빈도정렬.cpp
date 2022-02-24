#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, C, idx;
iii arr[1005];

bool cmp(iii a, iii b) {

    int cnta = get<0>(a);
    int cntb = get<0>(b);
    if (cnta != cntb) return cnta > cntb;
    
    int turna = get<1>(a);
    int turnb = get<1>(b);
    return turna < turnb;
}

int check(int x) {

    for (int j=0; j<idx; j++) {
        int n = get<2>(arr[j]);
        if (n == x) return j;
    }
    return -1;
}

int main() {

    scanf("%d %d", &N, &C);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);

        int ch = check(x);
        if (ch != -1) get<0>(arr[ch])++;
        else {
            get<0>(arr[idx]) = 1;
            get<1>(arr[idx]) = i;
            get<2>(arr[idx++]) = x;
        }
    }

    sort(arr, arr+idx, cmp);

    for (int i=0; i<idx; i++) {
        int n = get<2>(arr[i]);
        int cnt = get<0>(arr[i]);
        for (int j=0; j<cnt; j++)
            printf("%d ", n);
    }

    return 0;
}