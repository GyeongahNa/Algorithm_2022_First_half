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
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;


#define X first
#define Y second

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int R, C, N;
vvi board(205, vi(205, -1));


void putBomb(int t) {
    
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (board[i][j] == -1) board[i][j] = t;
        }
    }
}

bool OOB(int x, int y) {
    return x < 0 || x >= R || y < 0 || y >= C;
}

void removeBomb(int t) {
    
    vvb check(205, vb(205, false));
    
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (board[i][j] == -1 || t-board[i][j] != 3) continue;
            check[i][j] = true;
            for (int k=0; k<4; k++) {
                int nx = i+dx[k];
                int ny = j+dy[k];
                if (OOB(nx, ny)) continue;
                check[nx][ny] = true;
            }
        }
    }
    
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (check[i][j]) board[i][j] = -1;
        }
    }
}

void printboard() {
    
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (board[i][j] == -1) cout<<'.';
            else cout<<'O';
        }
        cout<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> R >> C >> N;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            char c;
            cin >> c;
            if (c == 'O') board[i][j] = 0;
        }
    }
    
    for (int t=2; t<=N; t++) {
        putBomb(t);
        removeBomb(t);
    }
    printboard();
    return 0;
}