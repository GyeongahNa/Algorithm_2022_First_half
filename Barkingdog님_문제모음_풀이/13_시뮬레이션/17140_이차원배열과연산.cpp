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
#define MX 2147483640

int r, c, k, t;
int H, W;
int A[110][110];

void R() {

    for (int i=0; i<101; i++) {

        int cnt[105] = {};
        for (int j=0; j<101; j++) {
            if (!A[i][j]) continue;
            cnt[A[i][j]]++;
        }

        vector<ii> v;
        for (int j=1; j<101; j++) {
            if (!cnt[j]) continue;
            v.push_back({cnt[j], j});
        }

        sort(v.begin(), v.end());

        for (int j=0; j<v.size(); j++) {
            A[i][j*2]= v[j].Y;
            A[i][j*2+1] = v[j].X; 
        }
        for (int j=2*v.size(); j<101; j++)
            A[i][j] = 0;
        
        W = max(W, 2*(int)v.size());
    }
}

void C() {

    for (int i=0; i<101; i++) {

        int cnt[105] = {};
        for (int j=0; j<101; j++) {
            if (!A[j][i]) continue;
            cnt[A[j][i]]++;
        }

        vector<ii> v;
        for (int j=1; j<101; j++) {
            if (!cnt[j]) continue;
            v.push_back({cnt[j], j});
        }

        sort(v.begin(), v.end());

        for (int j=0; j<v.size(); j++) {
            A[j*2][i]= v[j].Y;
            A[j*2+1][i] = v[j].X; 
        }
        for (int j=2*v.size(); j<101; j++)
            A[j][i] = 0;

        H = max(H, 2*(int)v.size());
    }
}

int main() {

    H = 3, W = 3;
    scanf("%d %d %d", &r, &c, &k);
    r -=1; c-=1;
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++)
            scanf("%d", &A[i][j]);
    }


    while (A[r][c] != k && t <= 100) {
        if (H >= W) R();
        else C();
        t++;
    }

    if (t > 100) t = -1;
    printf("%d", t);
    return 0;
}
