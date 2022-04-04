#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
int mn = INT_MAX;
vector<ii> v(20);
vector<int> arr(20, 0);

void combination(int k, int t1, int t2) {

    if (k != 0) mn = min(mn, abs(t1-t2));
    if (k == 10) return ;

    int st = 0;
    if (k != 0) st = arr[k-1]+1;
    for (int i=st; i<N; i++) {
        arr[k] = i;
        combination(k+1, t1*v[i].X, t2+v[i].Y);
    }
}

int main() {

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> v[i].X;
        cin >> v[i].Y;
    }

    combination(0, 1, 0);
    cout<<mn;
    return 0;
}