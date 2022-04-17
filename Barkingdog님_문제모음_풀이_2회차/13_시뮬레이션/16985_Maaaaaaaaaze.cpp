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

int dh[6] = {0, 0, 0, 0, -1, 1};
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};

int N = 5, mn = INT_MAX;
int arr[5];
bool check[5];
int tmp[5][5], picked[5][5];
int dist[5][5][5], board[5][5][5], input[5][5][5];


void rotate() {

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++)
            tmp[i][j] = picked[4-j][i];
    }

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) picked[i][j] = tmp[i][j];
    }
}


void setBoard(int t, int d) {

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) picked[i][j] = input[arr[t]][i][j];
    }

    for (int i=0; i<d; i++) rotate();
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) board[t][i][j] = picked[i][j];
    }
}


bool OOB(int h, int x, int y) {
    return h < 0 || h >=5 || x < 0 || x >= 5 || y < 0 || y >= 5;
}


int bfs() {

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            for (int k=0; k<5; k++) dist[i][j][k] = -1;
        }
    }

    queue<iii> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 0;

    while (!q.empty()) {

        iii cur = q.front();
        int ch = get<0>(cur);
        int cx = get<1>(cur);
        int cy = get<2>(cur);
        q.pop();

        if (ch == 4 && cx == 4 && cy == 4) return dist[4][4][4];
        
        for (int i=0; i<6; i++) {
            int nh = ch+dh[i];
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if (OOB(nh, nx, ny) || !board[nh][nx][ny]) continue;
            if (dist[nh][nx][ny] != -1) continue;
            q.push({nh, nx, ny});
            dist[nh][nx][ny] = dist[ch][cx][cy]+1;
        }
    }
    return INT_MAX;
}


void permutation(int k) {

    if (k == 5) {
        for (int num=0; num<(1<<10); num++) {
            int tmp = num;
            for (int t=0; t<5; t++) {
                setBoard(t, tmp%4);
                tmp /= 4;
            }
            if (board[0][0][0] && board[4][4][4]) mn = min(mn, bfs());
        }
        return ;
    }

    for (int i=0; i<5; i++) {
        if (check[i]) continue;
        check[i] = true;
        arr[k] = i;
        permutation(k+1);
        check[i] = false;
    }
}


int main() {

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            for (int k=0; k<5; k++) cin >> input[i][j][k];
        }
    }

    permutation(0);
    if (mn == INT_MAX) cout<<-1;
    else cout<<mn;
    return 0;
}