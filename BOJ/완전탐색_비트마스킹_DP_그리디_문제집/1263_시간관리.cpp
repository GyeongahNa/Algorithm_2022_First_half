#include <cstdio>
#include <cstring>
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
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
vector<ii> v;

int main() {

    cin >> N;
    for (int i=0; i<N; i++) {
        int T, S;
        cin >> T >> S;
        v.push_back({S, T});
    }
    sort(v.begin(), v.end(), greater<>());

    int t = 0;
    for (int i=0; i<N; i++) {
        if (i == 0) t = v[i].X-v[i].Y;
        else t = min(t, v[i].X)-v[i].Y;
    }
    
    if (t < 0) cout<<"-1";
    else cout<<t;
    return 0;
}