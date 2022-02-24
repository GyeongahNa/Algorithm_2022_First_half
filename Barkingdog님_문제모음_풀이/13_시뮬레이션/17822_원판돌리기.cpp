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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M, T;
deque<int> cir[55];

void rotate(int x, int d, int k) {

    for (int i=1; i<=N; i++) {
        if (i%x != 0) continue;
        if (d == 0) {
            for (int j=0; j<k; j++) {
                cir[i].push_front(cir[i].back());
                cir[i].pop_back();
            }
        }
        else if (d == 1) {
            for (int j=0; j<k; j++) {
                cir[i].push_back(cir[i].front());
                cir[i].pop_front();
            }
        }
    }
}

int erase() {

    int tmp[55][55];
    for (int i=1; i<=N; i++) {
        for (int j=0; j<M; j++) 
            tmp[i][j] = cir[i][j];
    }

    int check = 0;
    for (int i=1; i<=N; i++) {
        for (int j=0; j<M; j++) {
            if (!cir[i][j]) continue;

            for (int k=0; k<4; k++) {
                int nx = i+dx[k];
                int ny = j+dy[k];

                if (ny < 0) ny = M-1;
                else if (ny >= M) ny = 0;

                if (nx < 1 || nx > N) continue;
                if (cir[i][j] != cir[nx][ny]) continue;

                tmp[i][j] = 0;
                tmp[nx][ny] = 0;
                check = 1;
            }
        }
    }
    
    for (int i=1; i<=N; i++) {
        for (int j=0; j<M; j++) 
            cir[i][j] = tmp[i][j];
    }
    return check;
}

void calc() {

    int t = 0, cnt = 0;
    for (int i=1; i<=N; i++) {
        for (int j=0; j<M; j++) {
            if (!cir[i][j]) continue;
            t += cir[i][j];
            cnt++;
        }
    }

    for (int i=1; i<=N; i++) {
        for (int j=0; j<M; j++) {
            if (!cir[i][j]) continue;
            if (cir[i][j]*cnt > t) cir[i][j]--;
            else if (cir[i][j]*cnt < t) cir[i][j]++;
        }
    }
}

int main() {

    scanf("%d %d %d", &N, &M, &T);
    for (int i=1; i<=N; i++) {
        for (int j=0; j<M; j++) {
            int x;
            scanf("%d", &x);
            cir[i].push_back(x);
        }
    }
 
    while (T--) {
        int x, d, k;
        scanf("%d %d %d", &x, &d, &k);
        rotate(x, d, k);
        if (!erase()) calc();
    }

    int re = 0;
    for (int i=1; i<=N; i++) {
        for (int j=0; j<M; j++)
            re += cir[i][j];
    }
    printf("%d", re);
    return 0;
}