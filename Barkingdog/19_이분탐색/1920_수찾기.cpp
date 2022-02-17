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
#include <limits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second


int N, M;
int A[100005];

int binarySearch(int x) {

    int first = 0;
    int last = N-1;
    int mid;

    while (first <= last) {

        mid = (first+last)/2;
        if (A[mid] == x) return 1;
        else if (A[mid] < x) first = mid+1;
        else last = mid-1;
    }
    return 0;
}


int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &A[i]);
    sort(A, A+N);

    scanf("%d", &M);
    while (M--) {
        int x;
        scanf("%d", &x);
        printf("%d\n", binarySearch(x));
    }
    return 0;
}