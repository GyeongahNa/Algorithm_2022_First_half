#include <cstdio>
#include <cstring>
#include <climits>
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


int N, M, Q;
int A[55][55];
int arr[10];
int isused[10];
vector<iii> v;
int mn = INT_MAX;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


void roateArray(int tmp[55][55]) {

    for (int i=0; i<Q; i++) {
        int r = get<0>(v[arr[i]]);
        int c = get<1>(v[arr[i]]);
        int s = get<2>(v[arr[i]]);

        for (int j=2*s+1; j>1; j-=2) {

            int x = r-j/2;
            int y = c-j/2;
            int first = tmp[x][y];

            for (int d=0; d<4; d++) {
                for (int k=0; k<j-1; k++) {
                    tmp[x][y] =  tmp[x+dx[d]][y+dy[d]];
                    x += dx[d];
                    y += dy[d];
                }
            }

            tmp[r-j/2][c-j/2+1] = first;
        }
    }
}


void getval(int tmp[55][55]) {

    int val = INT_MAX;
    for (int i=1; i<=N; i++) {
        int t = 0;
        for (int j=1; j<=M; j++)
            t += tmp[i][j];
        val = min(val, t);
    }
    mn = min(mn, val);
}


void func(int k) {

    if (k == Q) {

        int tmp[55][55] ={};
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=M; j++) 
                tmp[i][j] = A[i][j];
        }

        roateArray(tmp);
        getval(tmp);
        return ;
    }

    for (int i=0; i<Q; i++) {
        if (isused[i]) continue;
        arr[k] = i;
        isused[i] = 1;
        func(k+1);
        isused[i] = 0;
    }
}


int main() {

    scanf("%d %d %d", &N, &M, &Q);
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++)
            scanf("%d", &A[i][j]);
    }

    for (int i=0; i<Q; i++) {
        int r, c, s;
        scanf("%d %d %d", &r, &c, &s);
        v.push_back({r, c, s});
    }

    func(0);
    printf("%d", mn);
    return 0;
}