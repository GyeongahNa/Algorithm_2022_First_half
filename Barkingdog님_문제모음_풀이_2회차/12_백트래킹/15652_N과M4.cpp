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

int M, N;
int arr[10];

void combination(int k) {

    if (k == M) {
        for (int i=0; i<M; i++) cout<<arr[i]<<" ";
        cout<<"\n";
        return ;
    }

    int st = 1;
    if (k != 0) st = arr[k-1];
    for (int i=st; i<=N; i++) {
        arr[k] = i;
        combination(k+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    combination(0);
    return 0;
}