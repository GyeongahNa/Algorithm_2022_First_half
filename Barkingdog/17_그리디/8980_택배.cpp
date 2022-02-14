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

int N, C, M, re;
iii arr[10005];
int truck[2005];


int main() {

    scanf("%d %d\n %d", &N, &C, &M);
    for (int i=0; i<M; i++) {
        int f, t, b;
        scanf("%d %d %d", &f, &t, &b);
        arr[i] = {t, f, b};
    }
    sort(arr, arr+M);

    for (int i=0; i<M; i++) {
        
        int f, t, b;
        tie(t, f, b) = arr[i];
        for (int j=f; j<t; j++) 
            b = min(b, C-truck[j]);
        for (int j=f; j<t; j++) 
            truck[j] += b;
        re += b;
    }
    printf("%d", re);
    return 0;
}