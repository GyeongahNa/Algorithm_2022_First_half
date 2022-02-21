#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, M;
vector<ii> v;
vector<int> cnt(1005, 0);

int twoPointer() {

    int st = 0; //최솟값 포인터
    int en = 0; //최댓값 포인터
    int nclass = 0;
    int re = INT_MAX;

    while (en < N*M) {

        if (cnt[v[en].Y] == 0) nclass++;
        cnt[v[en].Y]++;
        en++;

        while (nclass == N) {
            re = min(re, v[en-1].X-v[st].X);
            cnt[v[st].Y]--;
            if (cnt[v[st].Y] == 0) nclass--;
            st++;
        }
    }
    return re;
}

int main() {

    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            int x;
            scanf("%d", &x);
            v.push_back({x, i});
        }
    }
    sort(v.begin(), v.end());
    printf("%d", twoPointer());
    return 0;
}