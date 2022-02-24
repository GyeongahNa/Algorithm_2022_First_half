#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int freq[2000001];

int main() {

    int N;
    scanf("%d", &N);

    vector<int> v(N);
    for (int i=0; i<N; i++)
        scanf("%d", &v[i]);
    
    int x;
    scanf("%d", &x);

    int cnt = 0;
    for (int e : v) {
        if (x < e) continue;
        if (freq[x-e]) cnt++;
        freq[e]++;
    }
    printf("%d", cnt);
    return 0;
}