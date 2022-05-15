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

int getPos(int x, char d, int L, int T) {

    int movedist = T%(2*L);

    if (d == 'D') {
            if (x+movedist<=L) return x+movedist;
            else if (L-(movedist-(L-x))>=0) return L-(movedist-(L-x));
            return movedist-(L-x)-L;
    }
    if (x >= movedist) return x-movedist;
    else if (movedist-x <= L) return movedist-x; 
    return L-(movedist-x-L);
}

int main() {

    int L, T, N;
    scanf("%d %d\n%d", &L, &T, &N);

    vector<int> vpos;
    for (int i=0; i<N; i++) {
        int x;
        char dir;
        scanf("%d %c", &x, &dir);
        vpos.push_back(getPos(x, dir, L, T));
    }

    sort(vpos.begin(), vpos.end());
    for (int i=0; i<N; i++) printf("%d ", vpos[i]);
    return 0;
}