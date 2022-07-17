#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n, x, y, dir, t;

int main() {

    cin >> n;
    for (int d=1; d<=n; d++) {
        for (int i=0; i<2; i++) {
            for (int j=0; j<d; j++) {
                x += dx[dir];
                y += dy[dir];
                t += 1;
                if (t == n) {
                    cout<<x<<" "<<y;
                    return 0;
                }
            }
            dir = (dir+1)%4;
        }
    }
    cout<<x<<" "<<y;
    return 0;
}