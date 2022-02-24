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

int N, Q;
int sz;
int A[65][65];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


int getPow(int n, int k) {

    int re = 1;
    for (int i=0; i<k; i++)
        re *= n;
    return re;
}


void rotate(int x,  int y, int length) {

    int tmp1[65][65] = {};
    int tmp2[65][65] = {};

    for (int i=0; i<length; i++) {
        for (int j=0; j<length; j++)
            tmp1[i][j] = A[i+x][j+y];
    }

    for (int i=0; i<length; i++) {
        for (int j=0; j<length; j++)
            tmp2[i][j] = tmp1[length-1-j][i];
    }

    for (int i=0; i<length; i++) {
        for (int j=0; j<length; j++)
            A[i+x][j+y] = tmp2[i][j];
    }
} 


void devideSquare(int L) {

    int length = getPow(2, L);
    for (int i=0; i<sz; i+=length) {
        for (int j=0; j<sz; j+=length) {
            rotate(i, j, length);
        }
    }
}


void removeIce() {

    int tmp[65][65] = {};

    for (int i=0; i<sz; i++) {
        for (int j=0; j<sz; j++) {
            
            int cnt = 0;
            for (int k=0; k<4; k++) {
                int nx = i+dx[k];
                int ny = j+dy[k];
                if (nx < 0 || nx >= sz || ny < 0 || ny >= sz) continue;
                if (!A[nx][ny]) continue;
                cnt++;
            }
            if (cnt < 3 && A[i][j] > 0) tmp[i][j]++;
        }
    }

    for (int i=0; i<sz; i++) {
        for (int j=0; j<sz; j++) {
            if (!tmp[i][j]) continue;
            A[i][j] -= 1;
        }
    }
}


int getSum () {

    int re = 0;
    for (int i=0; i<sz; i++) {
        for (int j=0; j<sz; j++) {
            if (!A[i][j]) continue;
            re += A[i][j];
        }
    }
    return re;
}


int getMaxIce() {

    bool visited[65][65];
    memset(visited, false, sizeof(visited));

    int re = 0;
    for (int i=0; i<sz; i++) {
        for (int j=0; j<sz; j++) {
            if (!A[i][j] || visited[i][j]) continue;

            queue<ii> q;
            q.push({i, j});
            visited[i][j] = true;

            int cnt = 0;
            while (!q.empty()) {

                ii cur = q.front();
                q.pop();
                cnt++;

                for (int k=0; k<4; k++) {
                    int nx = cur.X+dx[k];
                    int ny = cur.Y+dy[k];

                    if (nx < 0 || nx >= sz || ny < 0 || ny >= sz) continue;
                    if (!A[nx][ny] || visited[nx][ny]) continue;

                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
            re = max(re, cnt);
        }
    }
    return re;
}


int main() {

    scanf("%d %d", &N, &Q);
    
    sz = getPow(2, N);
    for (int i=0; i<sz; i++) {
        for (int j=0; j<sz; j++)
            scanf("%d", &A[i][j]);
    }

    while (Q--) {
        int L;
        scanf("%d", &L);
        devideSquare(L);
        removeIce();
    }

    printf("%d\n", getSum());
    printf("%d\n", getMaxIce());

    return 0;
}

/*상하좌우의 얼음을 체크해서 A[i][j]-- 할때, A의 모든 위치를 체크하기 전에 특정 위치의 얼음을 줄이지 않도록 주의*/
/*bfs 할 때마다 visited 배열 초기화 주의*/