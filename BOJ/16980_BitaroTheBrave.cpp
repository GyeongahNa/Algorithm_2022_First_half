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

int H, W;
long long ret;
char board[3005][3005];
int cntO[3005][3005];
int cntJ[3005][3005];

int main() {

    cin >> H >> W;
    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) cin >> board[i][j];
    }

    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) {
            cntO[i][j] = cntO[i][j-1]+(board[i][j] == 'O');
            cntJ[i][j] = cntJ[i-1][j]+(board[i][j] == 'I');
        }
    }

    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) {
            if (board[i][j] != 'J') continue;
            ret += (cntO[i][W]-cntO[i][j])*(cntJ[H][j]-cntJ[i][j]);
        }
    }
    cout<<ret;
    return 0;
}