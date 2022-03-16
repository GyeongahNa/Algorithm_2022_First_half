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
#include <climits>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second
#define INF INT_MAX

string s;
char board[10][10];

int T, r, c, cnt;
int mnpin, mnmoves;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


bool OOB(int x, int y) {
    return x < 0 || x >= r || y < 0 || y >= c;
}

void backTracking(int npin, int nmoves) {

    if (npin < mnpin) {
        mnpin = npin;
        mnmoves = nmoves;
    }
    else if (npin == mnpin) mnmoves = min(mnmoves, nmoves);


    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (board[i][j] != 'o') continue;

            for (int k=0; k<4; k++) {
                int nx1 = i+dx[k];
                int ny1 = j+dy[k];
                int nx2 = i+dx[k]*2;
                int ny2 = j+dy[k]*2;
                if (OOB(nx1, ny1) || OOB(nx2, ny2)) continue;
                if (board[nx1][ny1] != 'o' || board[nx2][ny2] != '.') continue;
                
                board[i][j] = '.';
                board[nx1][ny1] = '.';
                board[nx2][ny2] = 'o';
                backTracking(npin-1, nmoves+1);
                board[i][j] = 'o';
                board[nx1][ny1] = 'o';
                board[nx2][ny2] = '.';
            }
        }
    }    
}

int main() {

    cin >> T;
    getline(cin, s);
    while (T--) {
        
        r = 0, cnt = 0;
        mnpin = INF, mnmoves = INF;

        while (1) {
            getline(cin, s);
            if (s == "") break;
            for (c=0; c<s.size(); c++) {
                board[r][c] = s[c];
                if (board[r][c] == 'o') cnt++;
            }
            r++;
        }

        backTracking(cnt, 0);
        cout<<mnpin<<" "<<mnmoves<<"\n";
    }
    return 0;
}