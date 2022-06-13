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

int board[10][10];
bool completed;

int dx[9] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
int dy[9] = {0, 1, 2, 0, 1, 2, 0, 1, 2};

void printboard() {

    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) 
            cout<<board[i][j];
        cout<<'\n';
    }
}

void backTracking(int k) {
    
    if (completed) return ;
    if (k == 81) {
        printboard();
        completed = true;
        return ;
    }
    
    int row = k/9;
    int col = k%9;

    if (board[row][col]) {
        backTracking(k+1);
        return ;
    }
    
    vb check(10, false);
    int stx = row-(row%3);
    int sty = col-(col%3);
    
    for (int i=0; i<9; i++) {
        check[board[row][i]] = true;
        check[board[i][col]] = true;
        check[board[stx+dx[i]][sty+dy[i]]] = true;
    }
    
    for (int i=1; i<=9; i++) {
        if (check[i]) continue;
        board[row][col] = i;
        backTracking(k+1);
        board[row][col] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    for (int i=0; i<9; i++) {
        string s;
        cin >> s;
        for (int j=0; j<9; j++) board[i][j] = s[j]-'0';
    }
    
    backTracking(0);
    return 0;
}