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

int M, N;
int snack[1000005];

int binarySearch() {

    int first = 1;
    int last = 1000000000;
    int re = 0;
    int mid, cnt;

    while (first <= last) {
        mid = (first+last)/2;
        cnt = 0;
        for (int i=0; i<N; i++)
            cnt += snack[i]/mid;
        if (cnt >= M) {
            re = mid;
            first = mid+1;
        }
        else last = mid-1;
    }
    return re;
}

int main() {

    scanf("%d %d", &M, &N);
    for (int i=0; i<N; i++) scanf("%d", &snack[i]);

    printf("%d", binarySearch());
    return 0;
}