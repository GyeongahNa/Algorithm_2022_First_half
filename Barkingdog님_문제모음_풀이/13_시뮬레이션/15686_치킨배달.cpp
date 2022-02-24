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

int N, M;
int city[55][55];

int nhouse;
ii house[200];
int nchicken;
ii chicken[20];
int isused[20];

int mn;
int arr[20];

int chickenDist() {
    
    int t = 0;
    for (int i=0; i<nhouse; i++) { 
        int dist = 100000000;
        for (int j=0; j<M; j++) {
            int rdist = max(house[i].X-chicken[arr[j]].X, chicken[arr[j]].X-house[i].X);
            int cdist = max(house[i].Y-chicken[arr[j]].Y, chicken[arr[j]].Y-house[i].Y);
            dist = min(dist, rdist+cdist);
        }
        t += dist;
    }
    return t;
}

void func(int k) {

    if (k == M) {
        mn = min(mn, chickenDist());
        return ;
    }

    int st = 0;
    if (k != 0) st = arr[k-1]+1;
    for (int i=st; i<nchicken; i++) {
        if (isused[i]) continue;
        arr[k] = i;
        isused[i] = 1;
        func(k+1);
        isused[i] = 0;
    }
}

int main() {

    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &city[i][j]);
            if (city[i][j] == 1) {
                house[nhouse] = {i, j};
                nhouse++;
            }
            else if (city[i][j] == 2) { 
                chicken[nchicken] = {i, j};
                nchicken++;
            }
        }
    }

    mn = 100000000;
    func(0);
    printf("%d", mn);
    return 0;
}