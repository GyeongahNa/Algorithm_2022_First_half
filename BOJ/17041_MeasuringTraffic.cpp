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

int n, p, cnt;
int t[10005];

int main() {

    cin >> n >> p;
    for (int i=0; i<n; i++) cin >> t[i];

    for (int i=0; i<n; i++) {
        if (t[i] == 0) continue;
        if (i == 0 || t[i] < t[i-1]) cnt++;
    }

    if (cnt && cnt != p) {
        cout<<"ambiguous";
        return 0;
    }

    for (int i=0; i<n; i++) {
        if (i > 0 && t[i] < t[i-1]) cnt--;
        cout<<cnt<<"\n";
    }
    return 0;
}
