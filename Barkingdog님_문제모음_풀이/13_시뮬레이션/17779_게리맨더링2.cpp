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
#define MX 2147680

int N;
int board[25][25];

int cal(int x, int y, int d1, int d2) {

    int area[25][25] = {};

    for (int i=1; i<x+d1; i++) {
        for (int j=1; j<=y; j++)
            if (i+j < x+y) area[i][j] = 1;
    }

    for (int i=1; i<=x+d2; i++) {
        for (int j=y+1; j<=N; j++)
            if (i-j < x-y) area[i][j] = 2;
    }

    for (int i=x+d1; i<=N; i++) {
        for (int j=1; j<y-d1+d2; j++)
            if (i-j > x-y+2*d1) area[i][j] = 3;
    }

    for (int i=x+d2+1; i<=N; i++) {
        for (int j=y-d1+d2; j<=N; j++)
            if (i+j > x+y+2*d2) area[i][j] = 4;
    }

    int s[6] = {};
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++)
            s[area[i][j]] += board[i][j];
    }

    int mx = *max_element(s, s+5);
    int mn = *min_element(s, s+5);
    return mx-mn;
}

int main() {

    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++)
            scanf("%d", &board[i][j]);
    }

    int mn = MX;
    for (int d1=1; d1<N-1; d1++) {
        for (int d2=1; d2<N-1; d2++) {
            for (int x=1; x<=N; x++) {
                for (int y=1; y<=N; y++) {
                    if (x+d1 > N || x+d2 > N || x+d1+d2 > N) continue;
                    if (y-d1 < 1 || y+d2 > N || y-d1+d2 < 1 || y-d1+d2 > N ) continue;
                    mn = min(mn, cal(x, y, d1, d2));
                }
            }
        }
    }
    printf("%d", mn);
    return 0;
}