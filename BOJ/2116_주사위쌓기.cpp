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
#include <map>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, mx;
int dice[10005][10];
int op[6] = {5, 3, 4, 1, 2, 0};

int getMaxBeside(int up, int down) {

    for (int i=6; i>=1; i--) {
        if (i == up || i == down) continue;
        return i;
    }
    return 0;
}

int findIdx(int ndice, int num) {

    for (int i=0; i<6; i++) {
        if (dice[ndice][i] == num) return i;
    }
    return -1;
}

int main() {
    
    cin >> N;
    for (int i=1; i<=N; i++) {
        for (int j=0; j<6; j++) cin >> dice[i][j];
    }
    
    for (int st=0; st<6; st++) {
        int sum = getMaxBeside(dice[1][st], dice[1][op[st]]);
        int num = dice[1][op[st]];
        for (int i=2; i<=N; i++) {
            int idx = findIdx(i, num);
            sum += getMaxBeside(dice[i][idx], dice[i][op[idx]]);
            num = dice[i][op[idx]];
        }
        mx = max(sum, mx);
    }
    cout<<mx;
    return 0;
}