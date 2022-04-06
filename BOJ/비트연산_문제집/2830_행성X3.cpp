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

int N;
unsigned long long ret;
vector<unsigned long long> v(1000005, 0);

int main() {

    cin >> N;
    for (int i=0; i<N; i++) cin >> v[i];

    for (int i=31; i>=0; i--) {
        
        unsigned long long cnt0 = 0, cnt1 = 0;
        for (int j=0; j<N; j++) {
            if (v[j]&(1ULL<<i)) cnt1++;
            else cnt0++;
        }

        for (int j=0; j<N; j++) {
            if (v[j]&(1ULL<<i)) ret += (1ULL<<i)*cnt0;
            else ret += (1ULL<<i)*cnt1;
        }
    }
    cout<<ret/2;
    return 0;
}