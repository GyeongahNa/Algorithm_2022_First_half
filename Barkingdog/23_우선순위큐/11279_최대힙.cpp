#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using str = string;

#define X first
#define Y second

int N;
priority_queue<int> pq;

int main() {

    scanf("%d", &N);
    while (N--) {
        int x;
        scanf("%d", &x);
        if (x) pq.push(x);
        else {
            if (pq.empty()) printf("0\n");
            else {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
    }
    return 0;
}