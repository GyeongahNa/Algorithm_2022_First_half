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

int N;
int mn = INT_MAX;
vector<int> snow;
vector<iii> snowman; 

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        snow.push_back(x);
    }

    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++)
            snowman.push_back({snow[i]+snow[j], i, j});
    }
    sort(snowman.begin(), snowman.end());

    for (int i=0; i<snowman.size(); i++) {
        for (int j=i+1; j<snowman.size(); j++) {
            if (get<1>(snowman[i]) == get<1>(snowman[j])) continue;
            if (get<1>(snowman[i]) == get<2>(snowman[j])) continue;
            if (get<2>(snowman[i]) == get<1>(snowman[j])) continue;
            if (get<2>(snowman[i]) == get<2>(snowman[j])) continue;
            mn = min(mn, get<0>(snowman[j])-get<0>(snowman[i]));
            break;
        }
    }

    printf("%d", mn);
    return 0;
}