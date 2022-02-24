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
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second
#define str string

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int N, M, K;
unordered_map<str, int> m;
vector<vector<char>> v(15, vector<char>(15));

ii convert(int nx, int ny) {
    
    if (nx == 0) nx = N;
    if (nx == N+1) nx = 1;
    if (ny == 0) ny = M;
    if (ny == M+1) ny = 1;
    return {nx, ny};
}

void dfs(int x, int y, str s) {

    if (s.size() >= 5) return ;
    s.push_back(v[x][y]);
    m[s]++;
    
    for (int i=0; i<8; i++) {
        ii nc = convert(x+dx[i], y+dy[i]);
        int nx = nc.X;
        int ny = nc.Y;
        dfs(nx, ny, s);
    }
}

int main() {

    scanf("%d %d %d", &N, &M, &K);
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) 
            scanf(" %c", &v[i][j]);
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++)
            dfs(i, j, "");
    }

    while (K--) {
        char tmp[10];
        scanf("%s", tmp);
        printf("%d\n", m[str(tmp)]);
    }
    return 0;
}

/*가능한 문자열을 unordered_multiset에 저장해두고 count 하는 대신
map<string, int>에 문자열의 등장 횟수를 기록함으로써 시간 단축*/