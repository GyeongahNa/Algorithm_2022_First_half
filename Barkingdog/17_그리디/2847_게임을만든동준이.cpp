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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, re;
int arr[105];

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &arr[i]);

    for (int i=0; i<N-1; i++) {
        for (int j=i; j>=0; j--) {
            if (arr[j] >= arr[j+1]) {
                re += (arr[j]-arr[j+1]+1);
                arr[j] = arr[j+1]-1;
            }
        }
    } 

    printf("%d", re);
    return 0;
}