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

int N, M;
long long card[1005];

int main() {

    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) scanf("%lld", &card[i]);
    
    while (M--) {
        sort(card, card+N);
        card[0] = card[0]+card[1];
        card[1] = card[0];
    }

    long long re = 0;
    for (int i=0; i<N; i++) re += card[i];
    printf("%lld", re);
    return 0;
}

/*
//O(MNlogN)
while (M--) {
    sort(card, card+N);
    card[0] = card[0]+card[1];
    card[1] = card[0];
}

//O(MN)
while (M--) {
    swap(card[0], *min_element(card, card+N));
    swap(card[1], *min_element(card, card+N));
    card[0] = card[0]+card[1];
    card[1] = card[0];
}

//O(MlogN): 우선순위 큐
while (M--)
    ll a = pq.top(); pq.pop();
    ll b = pq.top(); pq.pop();
    pq.push(a+b);
    pq.push(a+b);
}
*/