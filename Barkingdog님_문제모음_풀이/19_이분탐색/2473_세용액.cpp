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
#define LLMX __LONG_LONG_MAX__

int N;
long long arr[5005];


long long binarySearch(int idx, long long two) {

    int first = idx;
    int last = N-1;
    int mid;
    int mnmid;
    long long three;
    long long mnabs = LLMX;

    while (first <= last) {
        mid = (first+last)/2;
        three = arr[mid]+two;
        if (!three) return mid;
        else if (three > 0) last = mid-1;
        else first = mid+1;
        if (mnabs > abs(three)) {
            mnabs = abs(three);
            mnmid = mid;
        }
    }
    return mnmid;
}


int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%lld", &arr[i]);
    sort(arr, arr+N);

    long long absmn = LLMX;
    int f = 0, s = 0, t = 0;
    for (int i=0; i<N-2; i++) {
        for (int j=i+1; j<N-1; j++) {
            int k = binarySearch(j+1, arr[i]+arr[j]);
            long long threeabs = abs(arr[i]+arr[j]+arr[k]);
            if (threeabs < absmn) {
                absmn = threeabs;
                f = i, s = j, t = k;
            }
        }
    }

    printf("%lld %lld %lld", arr[f], arr[s], arr[t]);
    return 0;
}