#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ici = tuple<int, char, int>;

#define X first
#define Y second

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int A, B, N, M;
iii robots[105];
int board[105][105];
ici cmds[105];

int convd(char d) {
    
    if (d == 'N') return 3;
    if (d == 'E') return 2;
    if (d == 'S') return 1;
    return 0;
}

int proceed(int r) {

    int x, y, d;    
    tie(x, y, d) = robots[r];

    int nx = x+dx[d];
    int ny = y+dy[d];

    if (nx < 1 || nx > B || ny < 1 || ny > A) {
        cout<<"Robot "<<r<<" crashes into the wall";
        return 1;
    }

    if (board[nx][ny]) {
        cout<<"Robot "<<r<<" crashes into robot "<<board[nx][ny];
        return 2;
    }

    board[x][y] = 0;    
    board[nx][ny] = r;
    robots[r] = {nx, ny, d};
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> A >> B >> N >> M;
    for (int i=1; i<=N; i++) {
        int y, x;
        char d;
        cin >> y >> x >> d;
        int dir = convd(d);
        robots[i] = {B-(x-1), y, dir};
        board[B-(x-1)][y] = i;
    }

    int r, iter;
    char cmd;

    for (int i=0; i<M; i++) {
        cin >> r >> cmd >> iter;
        cmds[i] = {r, cmd, iter};
    }    

    for (int i=0; i<M; i++) {
        tie(r, cmd, iter) = cmds[i];
        while (iter--) {
            if (cmd == 'L') get<2>(robots[r]) = (get<2>(robots[r])+1)%4;
            else if (cmd == 'R') get<2>(robots[r]) = (get<2>(robots[r])+3)%4;
            else if (proceed(r)) return 0; 
        }
    }
    
    cout<<"OK";
    return 0;
}