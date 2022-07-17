#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
long long A[1000000];
long long B[1000000];

int binarySearch(int i) {

    int first = i+1;
    int last = N-1;
    int re = -1;

    while (first <= last) {
        int mid = (first+last)/2;
        if (B[mid] <= A[i]) {
            re = mid;
            first = mid+1;
        }
        else last = mid-1;
    }
    return re;
}

int main() {

    cin >> N;
    for (int i=0; i<N; i++) cin >> A[i];
    for (int i=0; i<N; i++) cin >> B[i];

    for (int i=0; i<N; i++)
        cout<<max(0, binarySearch(i)-i)<<" ";
    return 0;
}