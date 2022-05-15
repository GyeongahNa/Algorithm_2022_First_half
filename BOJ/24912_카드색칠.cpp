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

int N;
vector<int> v;

int main() {

    cin >> N; v.resize(N);
    for (int i=0; i<N; i++) {
        cin >> v[i];
        if (i != 0 && v[i] && v[i-1] == v[i]) {
            cout<<-1;
            return 0;
        }
    }

    for (int i=0; i<N; i++) {
        if (v[i]) continue;
        for (auto x : {1, 2, 3}) {
            if (i != 0 && v[i-1] == x || i != N-1 && v[i+1] == x) continue;
            v[i] = x;
            break;
        }

        if (!v[i]) {
            cout<<-1;
            return 0;
        }
    }

    for (auto x : v) cout<<x<<" ";
    return 0; 
}