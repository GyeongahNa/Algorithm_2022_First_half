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

int N, W, L;
int truck[1050];
int bridge[200];

int main() {
    scanf("%d %d %d", &N, &W, &L);
    for (int i=0; i<N; i++)
        scanf("%d", &truck[i]);
    
    int time = 0, out = 0, total = 0, idx = 0;
    while (out < N) {

        if (bridge[0]) {
            out++;
            total -= bridge[0];
            bridge[0] = 0;
        }
        for (int i=0; i<W-1; i++)
            bridge[i] = bridge[i+1];
        bridge[W-1] = 0;
        
        if (total+truck[idx] <= L) {
            bridge[W-1] = truck[idx];
            idx++;
            total += bridge[W-1];
        }
        time++;
    }
    printf("%d", time);
    return 0;
}