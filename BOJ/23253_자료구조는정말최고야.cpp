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

int N, M, k, x;

int main() {

    bool check = true;

    cin >> N >> M;
    while (M--) {
        cin >> k;
        int bf = 200005;
        while (k--) {
            cin >> x;
            if (bf <= x) check = false;
            bf = x;
        }
    }

    if (check) cout<<"Yes";
    else cout<<"No";
    return 0;
}