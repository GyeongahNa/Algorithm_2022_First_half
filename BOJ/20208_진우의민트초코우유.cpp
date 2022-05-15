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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M, H, sz, sx, sy, mx;
int arr[15];
bool check[15];
int board[15][15];
vector<ii> v;


bool isposs(int k) {

    int e = M - (abs(sx-v[arr[0]].X)+abs(sy-v[arr[0]].Y));
    if (e < 0) return false;
 
    for (int i=1; i<k; i++) {
        e += H;
        ii bf = v[arr[i-1]];
        ii cur = v[arr[i]];
        e -= (abs(bf.X-cur.X)+abs(bf.Y-cur.Y));
        if (e < 0) return false;
    }

    e += H;
    e -= (abs(sx-v[arr[k-1]].X)+abs(sy-v[arr[k-1]].Y));
    if (e < 0) return false;
    return true;
}

void permutation(int k) {

    if (k >= 1) {
        if (isposs(k)) mx = max(mx, k);
        if (k == sz) return ;
    }

    for (int i=0; i<sz; i++) {
        if (check[i]) continue;
        arr[k] = i;
        check[i] = true;
        permutation(k+1);
        check[i] = false;
    }
}

int main() {

    cin >> N >> M >> H;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) v.push_back({i, j});
            else if (board[i][j] == 1) { sx = i, sy = j; }
        }
    }

    sz = v.size();
    permutation(0);
    cout<<mx;
    return 0;
}