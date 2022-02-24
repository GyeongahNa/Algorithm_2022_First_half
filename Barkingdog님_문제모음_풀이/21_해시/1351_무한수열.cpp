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

long long N, P, Q;
unordered_map<long long, long long> m;

long long dynamic(long long n) {

    if (m.find(n) != m.end()) return m[n];
    m[n] = dynamic(n/P)+dynamic(n/Q);
    return m[n];
}

int main() {

    scanf("%lld %lld %lld", &N, &P, &Q);
    m[0] = 1;
    printf("%lld", dynamic(N));
    return 0;
}