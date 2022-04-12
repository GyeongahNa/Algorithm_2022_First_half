#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M, sz;
int mn = INT_MAX;
vector<int> open(15, 0);
vector<ii> chicken;
vector<vector<int>> board(55, vector<int>(55, 0));


int getDist(int x, int y) {

    int mdist = INT_MAX;
    for (int i=0; i<M; i++) {
        mdist = min(abs(x-chicken[open[i]].X)+abs(y-chicken[open[i]].Y), mdist);
    }
    return mdist;
}

void combination(int k) {

    if (k == M) {
        int dist = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (board[i][j] != 1) continue;
                dist += getDist(i, j);
            }
        }
        mn = min(mn, dist);
        return ;
    }

    int st = 0;
    if (k != 0) st = open[k-1]+1;
    for (int i=st; i<chicken.size(); i++) {
        open[k] = i;
        combination(k+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) chicken.push_back({i, j});
        }
    }

    combination(0);
    cout<<mn;
    return 0;
}