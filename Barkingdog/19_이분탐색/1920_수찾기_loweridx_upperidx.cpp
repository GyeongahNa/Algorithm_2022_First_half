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


int N, M, x;
int A[500005];


int getLeft(int x) { //lower_idx

    int first = 0;
    int last = N;
    int mid;

    while (first < last) {
        mid = (first+last)/2;
        if (A[mid] >= x) last = mid;
        else first = mid+1;
    }
    return first;
}


int getRight(int x) { //upper_idx

    int first = 0;
    int last = N;
    int mid;

    while (first < last) {
        mid = (first+last)/2;
        if (A[mid] <= x) first = mid+1;
        else last = mid;
    }
    return first;
}


int cnt(int x) {
    return getRight(x)-getLeft(x);
}


int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &A[i]);
    sort(A, A+N);

    scanf("%d", &M);
    for (int i=0; i<M; i++) {
        scanf("%d", &x);
        printf("%d ", cnt(x));
    }
    return 0;
}

/* 
수열 A를 정렬하였을 때
x의 개수 = (오름차순을 유지할 때)x를 삽입할 수 있는 가장 왼쪽 위치 - x를 삽입할 수 있는 가장 오른쪽 위치
*/