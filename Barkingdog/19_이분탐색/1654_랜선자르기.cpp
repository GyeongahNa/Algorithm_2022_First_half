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

long K, N;
long arr[10005];

long binarySearch() {

    long first = 1;
    long last = INT_MAX;
    long mid, cnt;
    long re = 1;

    while (first <= last) {

        mid = (first+last)/2;
        cnt = 0; 
        for (long i=0; i<K; i++) 
            cnt += (arr[i]/mid);
        if (cnt >= N) {
            re = mid;
            first = mid+1;
        }
        else last = mid-1;
    } 
    return re;
}

int main() {

    scanf("%ld %ld", &K, &N);
    for (long long i=0; i<K; i++) scanf("%ld", &arr[i]);
    printf("%ld", binarySearch());
    return 0;
}

/*
parametric search
: 어떠한 조건을 만족하는 최댓값/최솟값을 찾는 문제(최적화 문제)를 binary search로 변형하여 푸는 것
*/