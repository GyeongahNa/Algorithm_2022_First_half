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

int N;

int main() {

    cin >> N;
    
    int d = 0, tmp = N;
    while (tmp) {
        tmp /= 2;
        d++;
    }
    cout<<(((N&(~(1<<(d-1)))) == 0) ? 1 : 0);
    return 0;
}