#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, re;
int board[25][25];
vector<vector<int>> v;
vector<ii> vseat;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


void findSeat() {

    for (int p=0; p<v.size(); p++) { //v[p][0] 사람의 자리 찾기

        ii tmp[25][25] = {};
        int mxlike = 0, mxempty = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                
                // 자리에 이미 다른 사람이 있는 경우
                if (board[i][j]) { 
                    tmp[i][j] = {-1, -1};
                    continue;
                }
                
                // 자리에 다른 사람이 없는 경우
                // 인접한 자리에 있는 좋아하는 사람들 수와 빈칸 파악
                int cntlike = 0, cntemp= 0;
                for (int k=0; k<4; k++) {
                    
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (!board[nx][ny]) cntemp++;

                    for (int l=1; l<5; l++) {
                        if (board[nx][ny] != v[p][l]) continue;
                        cntlike++;
                        break;
                    }
                }

                if (mxlike < cntlike) {
                    mxlike = cntlike;
                    mxempty = cntemp;
                }
                else if (mxlike == cntlike) 
                    mxempty = max(mxempty, cntemp);

                tmp[i][j] = {cntlike, cntemp};
            }
        }

        // 인접한 칸에 좋아하는 사람이 가장 많은 칸 선택(동일한 경우 빈칸이 가장 많은 칸)
        bool check = false;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (tmp[i][j].X != mxlike || tmp[i][j].Y != mxempty) continue;
                board[i][j] = v[p][0];
                vseat.push_back({i, j}); 
                check = true;
                break;
            }
            if (check) break;
        }
    }
}

void getScore() {

    for (int p=0; p<N*N; p++) {
        
        int cnt = 0;
        for (int i=0; i<4; i++) {
            int nx = vseat[p].X+dx[i];
            int ny = vseat[p].Y+dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            
            for (int j=1; j<5; j++) {
                if (board[nx][ny] != v[p][j]) continue;
                cnt++;
                break;
            }
        }

        if (cnt == 1) re += 1;
        else if (cnt == 2) re += 10;
        else if (cnt == 3) re += 100;
        else if (cnt == 4) re += 1000;
    }
}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N*N; i++) {
        int x, p1, p2, p3, p4;
        scanf("%d %d %d %d %d", &x, &p1, &p2, &p3, &p4);
        v.push_back({x, p1, p2, p3, p4});
    }
    findSeat();
    getScore();
    printf("%d", re);
    return 0;
}