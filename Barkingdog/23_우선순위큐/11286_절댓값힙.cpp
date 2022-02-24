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

class cmp {
public:
    bool operator() (int a, int b) {
        if (abs(a) != abs(b)) return abs(a) > abs(b);
        return a > b;
    }
};

int main() {

    int N;
    scanf("%d", &N);

    priority_queue<int, vector<int>, cmp> pq; 
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        if (x) pq.push(x);
        else {
            if (!pq.empty()) {
                printf("%d\n", pq.top());
                pq.pop();
            }
            else printf("0\n");
        }
    }
    return 0;
}