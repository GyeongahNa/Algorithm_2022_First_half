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
int arr[10];

void permutation(int k) {

    if (k == M) {
        for (int i=0; i<M; i++) cout<<arr[i]<<" ";
        cout<<"\n";
        return ;
    }

    for (int i=1; i<=N; i++) {
        arr[k] = i;
        permutation(k+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    permutation(0);
    return 0;
}