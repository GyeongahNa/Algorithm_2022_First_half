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
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, K;
int open1, open2;
int v[25];
int dp[25][25][25];

int cnt(int idx, int op1, int op2) {

    if (idx >= K) return 0;
    if (dp[idx][op1][op2] != -1) return dp[idx][op1][op2];
    int n1 = abs(op1-v[idx])+cnt(idx+1, v[idx], op2);
    int n2 = abs(op2-v[idx])+cnt(idx+1, v[idx], op1);
    dp[idx][op1][op2] = min(n1, n2);
    return dp[idx][op1][op2];
}

int main() {

    cin >> N >> open1 >> open2 >> K;
    for (int i=0; i<K; i++) cin >> v[i];
    memset(dp, -1, sizeof(dp));

    cout<<cnt(0, open1, open2);
    return 0;
}

/*
dp[idx][op1][op2]: 현재 op1, op2 번째 문이 열려있을 때 v[idx]~v[K-1]까지의 문을 여는 최소 이동 횟수
*/ 