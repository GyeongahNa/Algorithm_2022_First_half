#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <iostream>
#include <map>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second
#define MX 2147483640

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int R, C, T;
int A[55][55];
vector<ii> v;

void spread() {
    
    int tmp[55][55];
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++)
            tmp[i][j] = A[i][j];
    }

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (!A[i][j]) continue;
            for (int k=0; k<4; k++) {
                int nx = i+dx[k];
                int ny = j+dy[k];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (A[nx][ny] == -1) continue;
                
                tmp[nx][ny] += A[i][j]/5;
                tmp[i][j] -= A[i][j]/5;
            }
        }
    }   

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++)
            A[i][j] = tmp[i][j];
    }
}

void rotate() {

    int x = v[0].X;
    int y = v[0].Y;

    for (int i=x-1; i>0; i--)
        A[i][0] = A[i-1][0];

    for (int i=0; i<C-1; i++)
        A[0][i] = A[0][i+1];

    for (int i=0; i<x; i++)
        A[i][C-1] = A[i+1][C-1];

    for (int i=C-1; i>1; i--)
        A[x][i] = A[x][i-1];
    A[x][1] = 0;

    x = v[1].X;
    y = v[1].Y;

    for (int i=x+1; i<R-1; i++)
        A[i][0] = A[i+1][0];
    
    for (int i=0; i<C-1; i++)
        A[R-1][i] = A[R-1][i+1];

    for (int i=R-1; i>x; i--)
        A[i][C-1] = A[i-1][C-1];
    
    for (int i=C-1; i>1; i--) 
        A[x][i] = A[x][i-1];
    A[x][1] = 0;
}

int main() {

    scanf("%d %d %d", &R, &C, &T);
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            scanf("%d", &A[i][j]);
            if (A[i][j] == -1)
                v.push_back({i, j});
        }
    }

    while (T--) {
        spread();
        rotate();
    }
    
    int re = 0;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (A[i][j] == -1 || !A[i][j]) continue;
            re += A[i][j];
        }
    }
    printf("%d", re);
    return 0;
}