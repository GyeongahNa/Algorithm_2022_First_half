#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

void func(int K, int from, int to, vector<ii> &v) {

    if (K == 1) {
        v.push_back({from, to});
        return ;
    }

    int mid = 6-from-to;
    func(K-1, from, mid, v);
    v.push_back({from, to});
    func(K-1, mid, to, v);
    return ;
}

int main() {

    int K;
    scanf("%d", &K);

    vector<ii> v;
    func(K, 1, 3, v);
    printf("%d\n", (int)v.size());
    for (int i=0; i<(int)v.size(); i++)
        printf("%d %d\n", v[i].X, v[i].Y);
    return 0;
}