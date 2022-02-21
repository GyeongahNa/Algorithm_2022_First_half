#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, M;
vector<int> A;

int binarySearch(int idx) {

    int first = idx;
    int last = N-1;
    int mid;
    int re = -1;

    while (first <= last) {
        int mid = (first+last)/2;
        int diff = A[mid]-A[idx];
        if (diff == M) return mid;
        if (diff < M) first = mid+1;
        else {
            re = mid;
            last = mid-1;
        }
    }
    return re;
}


int main() {

    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        A.push_back(x);
    }
    sort(A.begin(), A.end());

    int mn = INT_MAX;
    for (int i=0; i<N; i++) {
        int re = binarySearch(i);
        if (re == -1) continue;
        mn = min(mn, A[re]-A[i]);
    }
    printf("%d", mn);
    return 0;
}