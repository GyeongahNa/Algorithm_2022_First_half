#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>
#include <deque>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, M;
int A[10];
int arr[10];
int check[10];

void combination(int k) {

    if (k == M) {
        for (int i=0; i<M; i++) cout<<A[arr[i]]<<" ";
        cout<<"\n";
        return ;
    }

    int st = 0;
    if (k != 0) st = arr[k-1]+1;
    for (int i=st; i<N; i++) {
        if (i!=0 && !check[i-1] && A[i-1] == A[i]) continue;
        arr[k] = i;
        check[i] = true;
        combination(k+1);
        check[i] = false;
    }
}

int main() {

    cin >> N >> M;
    for (int i=0; i<N; i++) cin >> A[i];
    sort(A, A+N);
    combination(0);
    return 0;
}