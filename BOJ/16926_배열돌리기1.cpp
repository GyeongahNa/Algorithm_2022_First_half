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

#define X first
#define Y second

int N, M, R;
int board[305][305];

void roate(int c) {
    
    int tmp = board[c][c];
    
    for (int j=c; j<M-(c-1); j++) board[c][j] = board[c][j+1];
    for (int i=c; i<N-(c-1); i++) board[i][M-(c-1)] = board[i+1][M-(c-1)];
    for (int j=M-(c-1); j>c; j--) board[N-(c-1)][j] = board[N-(c-1)][j-1];
    for (int i=N-(c-1); i>c; i--) board[i][c] = board[i-1][c];
    
    board[c+1][c] = tmp;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N >> M >> R;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) cin >> board[i][j];
    }
    
    int corner = min(N/2, M/2);
    
    while (R--) {
        for (int c=1; c<=corner; c++) roate(c);
    }
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) cout<<board[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}