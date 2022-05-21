#include <cstdio>
#include <cstring>
#include <cmath>
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

int N, K, sum, mx;
vector<int> v;

int main() {

    cin >> N >> K; v.resize(N);
    for (int i=0; i<N; i++) cin >> v[i];

    for (int i=0; i<K; i++) sum += v[i];
    mx = sum;

    for (int i=1; i<N; i++) {
        sum -= v[i-1];
        sum += v[(i+K-1)%N];
        mx = max(sum, mx);
    }
    cout<<mx;
    return 0;
}