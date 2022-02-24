#include <cstdio>
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
long long tot;
vector<long long> v;

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            int left = -v[i]-v[j];
            long long cnt = upper_bound(v.begin()+j+1, v.end(), left)-lower_bound(v.begin()+j+1, v.end(), left);
            tot += cnt;
        }
    }
    printf("%lld", tot);
    return 0;
}