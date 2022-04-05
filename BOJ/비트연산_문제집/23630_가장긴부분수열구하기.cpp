#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <climits>
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

int N, mx;
int A[1000005];

int main() {

    cin >> N;
    for (int i=0; i<N; i++) cin >> A[i];

    for (int i=0; i<32; i++) {
        int cnt = 0;
        for (int j=0; j<N; j++) {
            if (A[j]&(1<<i)) cnt++;
        }
        mx = max(mx, cnt);
    }
    cout<<mx;
    return 0;
}