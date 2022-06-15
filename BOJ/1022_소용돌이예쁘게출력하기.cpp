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
// #define OFFSET 5000

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int r1, c1, r2, c2, dir, mx;
int board[100][100];

bool isPrint(int x, int y) {

    if (r1 <= x && x <= r2 && c1 <= y && y <= c2) return true;
    return false;
}

bool OOB(int x, int y) {

    if (x < -5000 || x > 5000 || y < -5000 || y > 5000) return true;
    return false;
}

void fillBoard() {
    
    int x = 0, y = 0, num = 1;
    if (isPrint(x, y)) board[x-r1][y-c1] = num;

    for (int i=1; i<1000000; i++) {
        for (int j=0; j<2; j++) {
            for (int k=0; k<i; k++) {       
                if (OOB(x+dx[dir], y+dy[dir])) return ;
                x = x+dx[dir], y = y+dy[dir], num += 1;
                if (isPrint(x, y)) {
                    board[x-r1][y-c1] = num;
                    mx = num;
                }
            }
            dir = (dir+1)%4;
        }
    }
}

void printBoard() {
    
    mx = to_string(mx).size();
    
    for (int i=r1; i<=r2; i++) {
        for (int j=c1; j<=c2; j++) {
            int cont = board[i-r1][j-c1];
            int nspace = mx-to_string(cont).size();
            for (int k=0; k<nspace; k++) cout<<' ';
            cout<<cont<<' ';
        }
        cout<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> r1 >> c1 >> r2 >> c2;
    fillBoard();
    printBoard();
    return 0;
}