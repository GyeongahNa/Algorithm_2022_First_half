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

int N;
int A[100005];

int binarySearch(int i) {

    int first = i+1;
    int last = N-1;
    int mid = 0;
    int sum = 0;
    int mnabs = INT_MAX;
    int re = 0;

    while (first <= last) {
        
        mid = (first+last)/2;
        sum = A[i]+A[mid];

        if (sum == 0) return 0;
        if (sum > 0) last = mid-1;
        else first = mid+1;

        if (mnabs > abs(sum)) {
            re = sum;
            mnabs = abs(sum);
        }
    }
    return re;
}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &A[i]);
    
    int mnabs = INT_MAX, re = 0;
    for (int i=0; i<N-1; i++) {
        int sum = binarySearch(i);
        if (mnabs > abs(sum)) {
            re = sum;
            mnabs = abs(sum);
        }
    }

    printf("%d", re);
    return 0;
}