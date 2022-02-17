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

int N;
int A[1000005];
int sorted[1000005];
int nodup[1000005];


int binarySearch(int x, int len) {

    int first = 0;
    int last = len-1;
    int mid;

    while (first <= last) {
        mid = (first+last)/2;
        if (nodup[mid] == x) return mid;
        else if (x < nodup[mid]) last = mid-1;
        else first = mid+1;
    }
    return -1;
}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &A[i]);
        sorted[i] = A[i];
    }
    sort(sorted, sorted+N);

    int idx = 0;
    for (int i=0; i<N; i++) { //중복 제거
        if (i>0 && sorted[i] == sorted[i-1]) continue;
        nodup[idx++] = sorted[i];
    }

    for (int i=0; i<N; i++) 
        printf("%d ", binarySearch(A[i], idx));
    return 0;
}

/*
line 51-55
벡터와 unique 함수를 사용하면 손쉽게 중복을 제거 할 수 있음
unique 함수는 정렬이 되어있는 벡터에서 중복 값을 모두 뒤로 미루고 중복 값이 시작되는 위치 반환
erase 함수를 통해 중복값이 시작되는 위치부터 모두 제거
sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end())
*/