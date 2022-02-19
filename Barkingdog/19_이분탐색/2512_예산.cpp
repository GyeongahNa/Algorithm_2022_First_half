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

int N, M, tot, mx, limit;
int arr[10005];


int binarySearch() {

    int first = 1;
    int last = 100000;
    int mid, sum;
    int re = 1;

    while (first <= last) {
        
        sum = 0;
        mid = (first+last)/2;
        for (int i=0; i<N; i++)
            sum += min(mid, arr[i]);

        if (sum == M) return mid;
        if (sum < M) {
            re = mid;
            first = mid+1;
        }
        else last = mid-1;
    }
    return re;
}


int main() {
    
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
        tot += arr[i];
        mx = max(mx, arr[i]);
    }
    scanf("%d", &M);
    sort(arr, arr+N);

    if (M >= tot) {
        printf("%d", mx);
        return 0;
    }
    
    mx = 0;
    limit = binarySearch();
    for (int i=0; i<N; i++)
        mx = max(mx, min(arr[i], limit));
    printf("%d", mx);
    return 0;
}

/*이분탐색으로 탐색 범위를 줄이면서 결과값을 '기록'해두고 리턴하기*/