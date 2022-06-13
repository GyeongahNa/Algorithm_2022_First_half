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

int H, W;
int board[505][505];
bool water[505][505];

bool checkLeft(int x, int y) {
    
    while (y >= 0) {
        if (board[x][y]) return true;
        y -= 1;
    }
    return false;
}

bool checkRight(int x, int y) {
    
    while (y < W) {
        if (board[x][y]) return true;
        y += 1;
    }
    return false;
}

void fillLeft(int x, int y) {
    
    while (y >= 0) {
        if (board[x][y]) return ;
        water[x][y] = true;
        y -= 1;
    }
}

void fillRight(int x, int y) {
    
    while (y < W) {
        if (board[x][y]) return ;
        water[x][y] = true;
        y += 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> H >> W;
    for (int j=0; j<W; j++) {
        int x;
        cin >> x;
        for (int i=0; i<x; i++) board[H-1-i][j] = 1;
    }
    
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if (board[i][j]) continue;
            if (!checkLeft(i, j) || !checkRight(i, j)) continue;
            fillLeft(i, j);
            fillRight(i, j);
        }
    }

    int ans = 0;
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if (water[i][j]) ans++;
        }
    }
    cout<<ans;
    return 0;
}