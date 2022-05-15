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

int N, K;
vector<int> v;

int main() {

    cin >> N >> K;
    v.resize(N);

    for (int i=0; i<N; i++) cin >> v[i];

    int t = 0, n = 0;
    for (int i=1; i<N; i++) {
        n += (v[i]-v[0]);
        if (v[i] > v[0]) t++;
    }
    cout<<n<<" "<<t;
    return 0;
}