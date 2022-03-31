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
#define half 15

int N, cnt;
int arr[20];
bool chX[20], chR[40], chL[40];

void combination(int y) {

    if (y == N) {
        cnt++;
        return ;
    }

    for (int x=0; x<N; x++) {
        if (chX[x] || chR[x+y] || chL[x-y+half]) continue;
        chX[x] = true; chR[x+y] = true; chL[x-y+half] = true;
        arr[y] = x;
        combination(y+1);
        chX[x] = false; chR[x+y] = false; chL[x-y+half] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    combination(0);
    cout<<cnt;
    return 0;
}