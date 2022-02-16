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

int T;
long long x, y;

int main() {

    scanf("%d", &T);
    while (T--) {

        scanf("%lld %lld", &x, &y);
        y = y-x;
        
        long long d = sqrt(y);
        if (y == d*d) printf("%lld\n", 2*d-1);
        else if (y >= d*(d+1)+1) printf("%lld\n", 2*d+1);
        else printf("%lld\n", 2*d);
    }
    return 0;
}

/*
y가 제곱수인 경우 최소 이동 횟수 = 2*d-1
y가 두 제곱수 사이의 중앙값 이후인 경우 이동 횟수 = 2*d+1
이외의 경우 이동 횟수는 = 2*d
*/