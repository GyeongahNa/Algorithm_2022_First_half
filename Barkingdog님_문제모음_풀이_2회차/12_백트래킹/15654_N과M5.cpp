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

void permutation(int k) {

    if (k == M) {
        for (int i=0; i<M; i++) cout<<A[arr[i]]<<" ";
        cout<<"\n";
        return ;
    }

    for (int i=0; i<N; i++) {
        if (check[i]) continue;
        arr[k] = i;
        check[i] = true;
        permutation(k+1);
        check[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    for (int i=0; i<N; i++) cin >> A[i];
    sort(A, A+N);
    permutation(0);
    return 0;
}