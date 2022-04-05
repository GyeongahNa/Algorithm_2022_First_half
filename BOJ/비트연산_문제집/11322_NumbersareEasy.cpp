#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <climits>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
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

long long T, N;
long long P10[64];
long long arr[10000000];

int main() {

    P10[0] = 1;
    for (int i=1; i<19; i++) P10[i] = P10[i-1]*10;

    for (long long tmp=1; tmp<=(1LL<<20)-1; tmp++) {
        for (int j=0; j<19; j++) {
            if (tmp&(1<<j)) arr[tmp] += P10[j];           
        }
    }

    cin >> T;
    while (T--) {
        cin >> N;
        for (long long tmp=1; tmp<=(1LL<<20)-1; tmp++) {
            if (arr[tmp]%N == 0) {
                cout<<arr[tmp]<<"\n";
                break;
            }
        }
    }
    return 0;
}