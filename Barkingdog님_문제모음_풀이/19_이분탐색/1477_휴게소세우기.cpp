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


int N, M, L, mx;
vector<int> v, vdist;


int binarySearch() {

    int first = 1;
    int last = mx;
    int mid, cnt;
    int re = mx;

    while (first <= last) {
        mid = (first+last)/2;
        cnt = 0;
        for (int i=0; i<vdist.size(); i++)
            cnt += (vdist[i]+mid-1)/mid-1;
        if (cnt <= M) {
            re = mid;
            last = mid-1;
        }
        else first = mid+1; 
    }
    return re;
}


int main() {

    scanf("%d %d %d", &N, &M, &L);

    v.push_back(0);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }
    v.push_back(L);
    sort(v.begin(), v.end());

    for (int i=1; i<v.size(); i++) vdist.push_back(v[i]-v[i-1]);
    mx = *max_element(vdist.begin(), vdist.end());

    printf("%d", binarySearch());
    return 0;
}