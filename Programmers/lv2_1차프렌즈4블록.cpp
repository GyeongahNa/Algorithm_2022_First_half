#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int dx[4] = {0, 0, 1, 1};
int dy[4] = {0, 1, 0, 1};

int M, N;
char bd[40][40];


bool check(int x, int y) {
    
    if (bd[x][y] == ' ') return false;
    for (int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx < 0 || nx >= M || ny < 0 || ny >= N) return false;
        if (bd[nx][ny] != bd[x][y]) return false;
    }
    return true;
}


int erase() {
    
    char tmp[40][40];
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) tmp[i][j] = bd[i][j];
    }
    
    int cnt = 0;
    for (int x=0; x<M; x++) {
        for (int y=0; y<N; y++) {
            //(x, y)를 기준으로 4개가 같은 그림인지 확인
            if (!check(x, y)) continue;
            //4개가 같은 그림이면 지우기
            for (int k=0; k<4; k++) {
                int nx = x+dx[k];
                int ny = y+dy[k];
                if (tmp[nx][ny] == ' ') continue;
                tmp[nx][ny] = ' ';
                cnt++;
            }
        }
    }
    
    //지운 그림 보드로 다시 복사
    for (int i=0; i<M; i++) 
        for (int j=0; j<N; j++) bd[i][j] = tmp[i][j];
    return cnt;
}


void getDown(int c) {
    
    for (int r=M-1; r>=0; r--) {
        if (bd[r][c] == ' ') continue;
        int i;
        for (i = r+1; i<M && bd[i][c] == ' '; i++) {}
        char tmp = bd[r][c];
        bd[r][c] = ' ';
        bd[i-1][c] = tmp;
    }
}


int solution(int m, int n, vector<string> board) {
    
    M = m, N = n;
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) 
            bd[i][j] = board[i][j];
    }
    
    int ret = 0;
    while (1) {
        //4개가 뭉쳐있는 곳을 찾아 지우기
        int cnt = erase();
        //지운 개수가 0개 이면 종류
        if (!cnt) break;
        ret += cnt;
        //밑으로 블럭 이동
        for (int c=0; c<n; c++) getDown(c);
    }
    return ret;
}