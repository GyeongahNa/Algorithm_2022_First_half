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
vector<int> v(5005, 0);
vector<bool> check(5005, false);

int main() {

    cin >> N;
    for (int i=0; i<N; i++) cin >> v[i];

    int cnt = 1, ret = 0;
    for (int i=1; i<N; i++) {

        if (!check[i]) {
            check[i] = true;
            ret++;
            cnt++;
        }

        int idx = 2;
        for (int j=i+1; j<N; j++) {
            if (v[j] != (v[i]-1)*idx+1) continue;
            idx++;
            if (check[j]) continue;
            check[j] = true;
            cnt++;
        }

        if (cnt >= N) break;
    }
    cout<<ret;
    return 0;
}