#include <cstring>
#include <cmath>
#include <cstdio>
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
#include <string>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using ll = pair<long long, long long>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, S, E;
vector<ll> v;

long long getHdx(ll p1, ll p2, long long x) {

    return (p1.Y-p2.Y)*x-(p1.Y-p2.Y)*p1.X+p1.Y*(p1.X-p2.X);
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for (int i=0; i<=N; i++) {
        long long x, h;
        cin >> x >> h;
        v.push_back({x, h});
    }
    cin >> S >> E;

    int idx = 0;
    while (v[idx].X <= S) idx++;
    long long hdx1 = getHdx(v[idx-1], v[idx], S);
    long long dx1 = v[idx-1].X-v[idx].X;

    idx = 0;
    while (v[idx].X < E) idx++;
    long long hdx2 = getHdx(v[idx-1], v[idx], E);
    long long dx2 = v[idx-1].X-v[idx].X;

    long long up = abs(hdx1*dx2-hdx2*dx1);
    long long down = abs((S-E)*dx1*dx2);

    long long g = gcd(up, down);
    up = up/g;
    down = down/g;

    if (down == 1) cout<<up;
    else cout<<up<<"/"<<down;
    return 0;
}

/*
식을 세울 때 double 자료형 사용 x, 나눗셈을 곱셈으로 바꾸어 처리해야 함
*/ 