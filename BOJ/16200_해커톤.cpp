#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, cnt;
vector<int> v;

int main() {

    cin >> N;
    v.resize(N);
    for (int i=0; i<N; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int i = 0;
    while (i < N) {
        cnt++;
        i += v[i];
    }

    cout<<cnt;
    return 0;
}