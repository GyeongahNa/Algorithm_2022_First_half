#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iic = tuple<int, int, char>;

#define X first
#define Y second

int N, M;
int ncctv;
iic cctv[10];
char map[10][10];

int re = 100;

ii dir2[2] = {{0, 1}, {2, 3}};
ii dir3[4] = {{0, 3}, {3, 1}, {1, 2}, {2, 0}};
iii dir4[4] = {{0, 3, 1}, {3, 1, 2}, {1, 2, 0}, {2, 0, 3}};

void draw(int x, int y, int dir, vector<ii>& drew) {

    if (dir == 0) { //up
        for (int i=x-1; i>=0; i--) {
            if (map[i][y] == '6') break;
            if (map[i][y] >= '1' && '5' >= map[i][y]) continue;
            if (map[i][y] != '#') {
                map[i][y] = '#';
                drew.push_back({i, y});
            }
        }
    }
    else if (dir == 1) { //down
        for (int i=x+1; i<N; i++) {
            if (map[i][y] == '6') break;
            if (map[i][y] >= '1' && '5' >= map[i][y]) continue;
            if (map[i][y] != '#') {
                map[i][y] = '#';
                drew.push_back({i, y});
            }
        }
    }
    else if (dir == 2) { //left
        for (int j=y-1; j>=0; j--) {
            if (map[x][j] == '6') break;
            if (map[x][j] >= '1' && '5' >= map[x][j]) continue;
            if (map[x][j] != '#') {
                map[x][j] = '#';
                drew.push_back({x, j});
            }
        }
    }
    else { //right
        for (int j=y+1; j<M; j++) {
            if (map[x][j] == '6') break;
            if (map[x][j] >= '1' && '5' >= map[x][j]) continue;
            if (map[x][j] != '#') {
                map[x][j] = '#';
                drew.push_back({x, j});
            }
        }
    }
}

void func(int k) {

    if (k == ncctv) {
        int cnt = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (map[i][j] == '0') cnt++;
            }
        }
        re = min(re, cnt);
        return ;
    }

    int posx = get<0>(cctv[k]);
    int posy = get<1>(cctv[k]);
    char n = get<2>(cctv[k]);

    if (n == '1') {
        for (int i=0; i<4; i++) {
            vector<ii> drew;
            draw(posx, posy, i, drew);
            func(k+1);
            for (int j=0; j<drew.size(); j++)
                map[drew[j].X][drew[j].Y] = '0';
        }
    }
    else if (n == '2') {
        for (int i=0; i<2; i++) {
            vector<ii> drew;
            draw(posx, posy, dir2[i].X, drew);
            draw(posx, posy, dir2[i].Y, drew);
            func(k+1);
            for (int j=0; j<drew.size(); j++)
                map[drew[j].X][drew[j].Y] = '0';
        }
    }
    else if (n == '3') {
        for (int i=0; i<4; i++) {
            vector<ii> drew;
            draw(posx, posy, dir3[i].X, drew);
            draw(posx, posy, dir3[i].Y, drew);
            func(k+1);
            for (int j=0; j<drew.size(); j++)
                map[drew[j].X][drew[j].Y] = '0';
        }
    }
    else if (n == '4') {
        for (int i=0; i<4; i++) {
            vector<ii> drew;
            draw(posx, posy, get<0>(dir4[i]), drew);
            draw(posx, posy, get<1>(dir4[i]), drew);
            draw(posx, posy, get<2>(dir4[i]), drew);
            func(k+1);
            for (int j=0; j<drew.size(); j++) 
                map[drew[j].X][drew[j].Y] = '0';
        }
    }
    else { //n == 5
        vector<ii> drew;
        draw(posx, posy, 0, drew);
        draw(posx, posy, 1, drew);
        draw(posx, posy, 2, drew);
        draw(posx, posy, 3, drew);
        func(k+1);
        for (int j=0; j<drew.size(); j++)   
            map[drew[j].X][drew[j].Y] = '0';
    }
}

int main() {

    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf(" %c", &map[i][j]);
            if (map[i][j] >= '1' && map[i][j] <= '5') {
                cctv[ncctv] = {i, j, map[i][j]};
                ncctv++;
            }
        }
    }

    func(0);
    printf("%d", re);
    return 0;
}