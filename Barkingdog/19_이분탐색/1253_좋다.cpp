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

int N, cnt;
int A[2005];


bool binarySearch(int idx) {

    int first = 0;
    int last = N-1;
    int sum;

    while (first < last) {
        sum = A[first]+A[last];
        if (sum < A[idx]) first++;
        else if (sum > A[idx]) last--;
        else { //sum == A[idx]
            if (first != idx && last != idx) return true;
            if (first == idx) first++;
            else last--;
        }
    }
    return false;
}


int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &A[i]);
    sort(A, A+N);

    for (int i=0; i<N; i++) {
        if (binarySearch(i)) cnt++;
    }
    printf("%d", cnt);
    return 0;
}