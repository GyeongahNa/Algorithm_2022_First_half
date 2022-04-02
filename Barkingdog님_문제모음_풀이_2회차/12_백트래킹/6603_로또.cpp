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

int K;
int arr[10];

void combination(int k, const vector<int>& v) {

    if (k == 6) {
        for (int i=0; i<6; i++) cout<<v[arr[i]]<<" ";
        cout<<"\n";
        return ; 
    }

    int st = 0;
    if (k != 0) st = arr[k-1]+1;
    for (int i=st; i<K; i++) {
        arr[k] = i;
        combination(k+1, v);
    }
}

int main () {

    while (1) {
        cin >> K;
        if (K == 0) return 0;
        vector<int> v(K, 0);
        for (int i=0; i<K; i++) cin >> v[i];
        sort(v.begin(), v.end());
        combination(0, v);
        cout<<"\n";
    } 
    return 0;
}