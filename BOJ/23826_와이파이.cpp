#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
int x0, y0, E0;
vector<iii> v;

int main() {

    cin >> N;
    cin >> x0 >> y0 >> E0;
    v.resize(N);
    for (int i=0; i<N; i++) {
        int x, y, e;
        cin >> x >> y >> e;
        v[i] = {x, y, e};
    }

    int mx = 0;
    for (auto [a, b, e1] : v) {
        int pub = max(0, E0-(abs(x0-a)+abs(y0-b)));
        int hspot = 0;
        for (auto [c, d, e2]: v) {
            hspot += max(0, e2-(abs(a-c)+abs(b-d)));
        }
        if (pub > hspot) mx = max(mx, pub-hspot);
    }
    if (mx) cout<<mx<<" ";
    else cout<<"IMPOSSIBLE ";
    return 0;
}