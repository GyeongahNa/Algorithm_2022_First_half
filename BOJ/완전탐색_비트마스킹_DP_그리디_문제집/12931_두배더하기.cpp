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
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, cnt;
vector<int> v;

bool allZero() {

    for (auto x : v) if (x) return false;
    return true;
}

bool multwo() {

    for (auto x : v) if (x%2) return false;
    return true;
}

int main() {

    cin >> N;
    v.resize(N);
    for (int i=0; i<N; i++) cin >> v[i];

    while (!allZero()) {
        if (multwo()) for (auto &x : v) x /= 2;
        else {
            for (auto&x : v) {
                if (x%2 == 1) {
                    x -= 1;
                    break;
                }
            }
        }
        cnt++;
    }
    cout<<cnt;
    return 0;
}