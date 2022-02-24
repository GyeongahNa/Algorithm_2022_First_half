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
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, K;
vector<int> S;

int twoPointer() {

    int st = 0;
    int en = 0;
    int nleft = K;
    int cnt = 0;
    int mx = 0;
    
    while (st < N) {

        while (en < N && (S[en]%2 == 0 || (S[en]%2 == 1 && nleft >= 1))) {
            if (S[en]%2 == 0) cnt++;
            else nleft--;
            en++;
        }
        mx = max(mx, cnt);
        if (S[st]%2 == 0) cnt--;
        else nleft++;
        st++;
    }
    return mx;
}

int main() {

    scanf("%d %d", &N, &K);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        S.push_back(x);
    }

    printf("%d", twoPointer());
    return 0;
}