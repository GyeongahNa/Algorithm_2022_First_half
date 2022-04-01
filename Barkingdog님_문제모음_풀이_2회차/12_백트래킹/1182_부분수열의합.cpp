#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
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

int N, S, cnt;
int A[25];
int P2[25];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    P2[0] = 1;
    for (int i=1; i<25; i++) P2[i] = P2[i-1]*2;

    cin >> N >> S;
    for (int i=0; i<N; i++) cin >> A[i];

    for (int i=1; i<P2[N]; i++) {
        int tmp = i, sum = 0;
        for (int j=0; j<N; j++) {
            if (tmp%2) sum += A[j];
            tmp /= 2;
        }
        if (sum == S) cnt++;
    }

    cout<<cnt;
    return 0;
}