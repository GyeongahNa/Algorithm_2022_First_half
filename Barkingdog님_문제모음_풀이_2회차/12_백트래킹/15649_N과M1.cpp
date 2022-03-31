#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
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
int check[10];

void permutation(int k) {
    
    if (k == M) {
        for (int i=0; i<M; i++) cout<<arr[i]<<" ";
        cout<<"\n";
        return ;
    }

    for (int i=1; i<=N; i++) {
        if (check[i]) continue;
        check[i] = true;
        arr[k] = i;
        permutation(k+1);
        check[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    permutation(0);
}