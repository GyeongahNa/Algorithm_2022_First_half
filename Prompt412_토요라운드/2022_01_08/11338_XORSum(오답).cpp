#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;

#define X first
#define Y second

int main() {

    int T;
    scanf("%d", &T);

    while (T--) {

        int Q, K;
        scanf("%d %d", &Q, &K);

        vector<int> v;
        vector<int> op;
        while (Q--) {
            char s[200];
            scanf("%s", s);
            string str(s);

            if (str == "insert") {
                int x;
                scanf("%d", &x);
                v.push_back(x);
            }
            else {
                sort(v.begin(), v.end(), greater<int>());
                K = min(K, (int)v.size());
                int sum = 0;
                for (int i=0; i<K-1; i++) {
                    sum += v[i]^v[i+1];
                }
                printf("%d\n", sum);         
                }
        }
    }
    return 0;
}