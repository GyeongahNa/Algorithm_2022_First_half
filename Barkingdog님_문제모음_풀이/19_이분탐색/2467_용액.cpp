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
int arr[100005];

int binarySearch(int i) {

    int first = i+1;
    int last = N-1;
    int mid = 0;
    int sum = 0;
    int mnsum = INT_MAX;
    int mnidx = 0;

    while (first <= last) {
        
        mid = (first+last)/2;
        sum = arr[mid]+arr[i];
        if (!sum) return arr[mid];
        if (sum > 0) last = mid-1;
        else first = mid+1;
        if (abs(sum) < mnsum) {
            mnsum = abs(sum);
            mnidx = mid;
        }
    }
    return arr[mnidx];
}

int main() {
    
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &arr[i]);
    sort(arr, arr+N);

    int mn = INT_MAX;
    int n1 = 0, n2 = 0;
    for (int i=0; i<N; i++) {
        int num1 = arr[i];
        int num2 = binarySearch(i);
        if (mn > abs(num1+num2)) {
            mn = abs(num1+num2);
            n1 = num1;
            n2 = num2;
        }
    }
    printf("%d %d", n1, n2);
    return 0;
}