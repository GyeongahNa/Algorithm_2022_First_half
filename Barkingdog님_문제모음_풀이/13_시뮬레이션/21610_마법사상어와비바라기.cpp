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
int A[55][55];
int cloud[55][55];

int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

int diagx[4] = {-1, -1, 1, 1};
int diagy[4] = {-1, 1, -1, 1};


void moveCloud(int d, int s) {

    int tmpC[55][55] = {};
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (!cloud[i][j]) continue;

            int x = i, y = j;
            for (int k=0; k<s; k++) {
                x += dx[d];
                y += dy[d];
                if (x < 1) x = N;
                else if (x > N) x = 1;
                if (y < 1) y = N;
                else if (y > N) y = 1; 
            }
            tmpC[x][y] = 1;
        }
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++)
            cloud[i][j] = tmpC[i][j];
    }
}


void rain() {

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (!cloud[i][j]) continue;
            A[i][j]++;
        }
    }
}

void magic() {

    int tmp[55][55] = {};

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (!cloud[i][j]) continue;

            int cnt = 0;
            for (int k=0; k<4; k++) {
                int nx = i+diagx[k];
                int ny = j+diagy[k];
                if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
                if (!A[nx][ny]) continue;
                cnt++;
            }
            tmp[i][j] += cnt;
        }
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++)
            A[i][j] += tmp[i][j];
    }
}


void makeNewCloud() {

    int newcloud[55][55] = {};
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (A[i][j] < 2 || cloud[i][j]) continue;
            newcloud[i][j] = 1;
        }
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cloud[i][j] = newcloud[i][j];
            if (!cloud[i][j]) continue;
            A[i][j] -= 2;
        }
    }
}


int getSum() {

    int re = 0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++)
            re += A[i][j];
    }
    return re;
}


int main() {

    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++)
            scanf("%d", &A[i][j]);
    }

    cloud[N][1] = 1;
    cloud[N][2] = 1;
    cloud[N-1][1] = 1;
    cloud[N-1][2] = 1;


    for (int i=0; i<M; i++) {
        int d, s;
        scanf("%d %d", &d, &s);
        moveCloud(d, s);
        rain();
        magic();
        makeNewCloud();
    }
    printf("%d", getSum());
    return 0;
}

/*구름을 vector<ii>로 표현하는 것보다 int cloud[55][55]로 표현하였을 때 디버깅 용이*/