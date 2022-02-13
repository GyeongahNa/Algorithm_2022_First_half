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

int N;
int P[1005];

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &P[i]);
    sort(P, P+N);
    
    int re = 0, psum = 0;
    for (int i=0; i<N; i++) {
        re += (psum+P[i]);
        psum += P[i];
    }
    printf("%d", re);
    return 0;
}