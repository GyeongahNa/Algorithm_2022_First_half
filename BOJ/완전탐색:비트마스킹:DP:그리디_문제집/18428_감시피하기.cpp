#include <cstdio>
#include <cmath>
#include <cstring>
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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N;
int arr[5];
char tmp[10][10];
char board[10][10];
bool ret;

bool check() {

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (tmp[i][j] != 'S') continue;
            for (int k=0; k<4; k++) {
                int x = i, y = j;
                while (1) {
                    x += dx[k];
                    y += dy[k];
                    if (x < 0 || x > N || y < 0 || y > N || tmp[x][y] == 'O') break;
                    if (tmp[x][y] == 'T') return false;
                }
            }
        }
    }
    return true;
}

void combination(int k) {

    if (k == 3) {

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++)
                tmp[i][j] = board[i][j];
        }
        for (int i=0; i<3; i++) tmp[arr[i]/N][arr[i]%N] = 'O';
        if (check()) ret = true;
        return ;
    }

    int st = 0;
    if (k != 0) st = arr[k-1]+1;
    for (int i=st; i<N*N; i++) {
        if (board[i/N][i%N] != 'X') continue;
        arr[k] = i;
        combination(k+1);
    }
}

int main() {

    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) cin >> board[i][j];
    }

    combination(0);
    if (ret) cout<<"YES";
    else cout<<"NO";
    return 0;
}