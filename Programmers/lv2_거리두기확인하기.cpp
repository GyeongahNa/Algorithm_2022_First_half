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

#define X first
#define Y second

int dx1[4] = {-1, 1, 0, 0};
int dy1[4] = {0, 0, -1, 1};

int dx2[4] = {-1, -1, 1, 1};
int dy2[4] = {-1, 1, -1, 1};


bool OOB(int x, int y) {
    return x < 0 || x >= 5 || y < 0 || y >= 5;
}

int observe(const vector<string>& p) {
    
    int sz = 5;
    for (int i=0; i<sz; i++) {
        for (int j=0; j<sz; j++) {
            if (p[i][j] != 'P') continue;
            
            //상하좌우에 다른 사람(P)이 있으면 0 리턴 
            for (int k=0; k<4; k++) {
                int nx = i+dx1[k];
                int ny = j+dy1[k];
                if (OOB(nx, ny)) continue;
                if (p[nx][ny] == 'P') return 0;
            }

            //거리가 2인 상하좌우에 다른 사람이 있고, 중간에 칸막이가 없는 경우 0 리턴
            for (int k=0; k<4; k++) {
                int bx = i+dx1[k];
                int by = j+dy1[k];
                int nx = i+dx1[k]*2;
                int ny = j+dy1[k]*2;
                if (OOB(nx, ny) || p[nx][ny] != 'P') continue;
                if (p[bx][by] != 'X') return 0;
            }

            //대각선에 다른 사람이 있고, 중간에 칸막이가 없는 경우 0 리턴
            for (int k=0; k<4; k++) {
                int bx1 = i+dx2[k], by1 = j;
                int bx2 = i, by2 = j+dy2[k];
                int nx = i+dx2[k], ny = j+dy2[k];
                if (OOB(nx, ny) || p[nx][ny] != 'P') continue;
                if (p[bx1][by1] != 'X' || p[bx2][by2] != 'X') return 0;
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    
    vector<int> ret;
    for (auto p : places) ret.push_back(observe(p));
    
    return ret;
}