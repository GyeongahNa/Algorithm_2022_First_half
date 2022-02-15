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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int T, N;

int main() {

    scanf("%d", &T);
    while (T--) {
        
        scanf("%d", &N);
        for (int i=2; i*i<=N; i++) {
            int cnt = 0;
            while (N%i == 0) {
                cnt++;
                N /= i;
            }
            if (cnt) printf("%d %d\n", i, cnt);
        }
        if (N != 1) printf("%d %d\n", N, 1);
    }
    return 0;
}