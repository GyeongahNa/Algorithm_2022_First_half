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

#define LLMAX 18446744073709551615

unsigned long long N;
unsigned long long p2[64];

int main() {

    cin >> N;
    p2[0] = 1;
    for (int i=1; i<64; i++) p2[i] = p2[i-1]*2;

    for (int i=0; i<64; i++) {
        if (p2[i] == LLMAX-N+1) {
            cout<<64-i;
            return 0;
        }
    }
    return 0;
}