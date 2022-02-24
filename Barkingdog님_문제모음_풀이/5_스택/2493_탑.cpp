#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;

#define X first
#define Y second

int main() {

    int N;
    scanf("%d", &N);

    stack<ii> tower;
    tower.push({100000001, 0});
    for (int i=1; i<=N; i++) {
        int t;
        scanf("%d", &t);
        while (tower.top().X < t)
            tower.pop();
        printf("%d ", tower.top().Y);
        tower.push({t, i});
    }
    return 0;
}