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

int N, x, y;

int main() {
    
    scanf("%d %d %d", &N, &x, &y);

    int nround = 1;
    bool check = false;
    while (N > 1) {
        if ((x%2 == 1 && x+1 == y) || (y%2 == 1 && y+1 == x)) {
            check = true;
            printf("%d", nround);
            break;
        }
        x = (x+1)/2; y = (y+1)/2;
        N = (N+1)/2;
        nround++;
    }
    if (!check) printf("-1");
    return 0;
}