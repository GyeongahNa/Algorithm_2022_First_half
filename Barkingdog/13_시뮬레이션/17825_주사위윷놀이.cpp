#include <cstring>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <queue>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int re;
int num[10];
ii horse[4];
int arr[10];

vector<int> board[5] = {
    {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40},
    {13, 16, 19, 25, 30, 35, 40}, //v[0][5] 출발
    {22, 24, 25, 30, 35, 40}, //v[0][10] 출발
    {28, 27, 26, 25, 30, 35, 40},
    {0}}; //v[0][15] 출발

ii getnew(int x, int y, int k) {

    if (x == 0 && y == 5) return {1, num[k]-1};
    if (x == 0 && y == 10) return {2, num[k]-1};
    if (x == 0 && y == 15) return {3, num[k]-1};
    if (y+num[k] < board[x].size()) return {x, y+num[k]}; 
    return {4, 0}; //도착
}

int check(ii hpos, ii npos) {
    int dy[4] = {0, 4, 3, 4};
    
    int re = 1;
    if (hpos.X > 0 && hpos.X < 4 && npos.X > 0 && npos.X < 4) {
        int hy = hpos.Y-dy[hpos.X];
        int py = npos.Y-dy[npos.X];
        if (hy >= 0 && py >=0 && hy == py) return 0;
    }
    if (board[hpos.X][hpos.Y] == 40 && board[npos.X][npos.Y] == 40) return 0;
    if (hpos == npos) return 0;
    return 1;
}

void func(int k, int score) {

    if (k == 10) {
        re = max(re, score);
        return ;
    }

    for (int i=0; i<4; i++) {

        ii cur = horse[i];
        ii npos = getnew(cur.X, cur.Y, k);

        int poss = 1;
        for (int j=0; j<4; j++) {
            if (i == j) continue;
            if (horse[j].X == 4 && horse[j].Y == 0) continue;
            if (check(horse[j], npos)) continue;
            poss = 0;
            break;
        }

        if (!poss) continue;

        horse[i].X = npos.X;
        horse[i].Y = npos.Y;
        score += board[horse[i].X][horse[i].Y];
        arr[k] = i;
        func(k+1, score);
        
        score -= board[horse[i].X][horse[i].Y];
        horse[i].X = cur.X;
        horse[i].Y = cur.Y;
    }
}

int main() {

    for (int i=0; i<10; i++)
        scanf("%d", &num[i]);
    
    func(0, 0);
    printf("%d", re);
    return 0;
}