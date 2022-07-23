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

#define X first
#define Y second

int N;
int A[1000000];

int main() {

    cin >> N;
    for (int i=0; i<N; i++) cin >> A[i];
    for (int i=0; i<N-3; i++) {
        if (A[0] > A[N-1]) A[0]--;
        else A[N-1]--;
    }

    cout<<max(A[0], A[N-1])-1;
    return 0;
}