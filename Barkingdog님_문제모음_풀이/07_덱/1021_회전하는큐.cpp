#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;

int main() {

    int N, M;
    scanf("%d %d", &N, &M);

    deque<int> d;
    for (int i=1; i<=N; i++) d.push_back(i);

    int sum = 0;
    while (M--) {
        int x;
        scanf("%d", &x);

        int cnt = 0;
        while (d.front() != x) {
            d.push_back(d.front());
            d.pop_front();
            cnt++;
        }
        sum += min(cnt, (int)d.size()-cnt);
        d.pop_front();
    }
    printf("%d", sum);
    return 0;
}