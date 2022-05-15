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

int T, N, idx;

int main() {
    
    idx = 1; cin >> T;
    while (T--) {
        cin >> N;
        vector<int> v(N);
        for (int i=0; i<N; i++) cin >> v[i];
        sort(v.begin(), v.end());

        int re = 1;
        for (int i=1; i<N; i++) {
            if (v[i] == v[i-1] && re < v[i]) re++;
            else if (v[i] > v[i-1]) re++;
        }

        cout<<"Case #"<<idx++<<": "<<re<<"\n";
    }
    return 0;
}