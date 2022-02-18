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

int N, M;
int arr[500005];

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &arr[i]);
    sort(arr, arr+N);
    
    scanf("%d", &M);
    while (M--) {
        int x;
        scanf("%d", &x);
        printf("%d ", binary_search(arr, arr+N, x));
    }
    return 0;
}