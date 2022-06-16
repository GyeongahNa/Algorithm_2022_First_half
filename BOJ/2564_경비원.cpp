#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int H, W, num, dn, dx, sum;
vector<ii> v;

ii conv(int n, int x) {
    
    if (n == 1) return {0, x};
    if (n == 2) return {H, x};
    if (n == 3) return {x, 0};
    return {x, W};
}

int main() {
    
    cin >> W >> H >> num;
    v.resize(num);
    
    for (int i=0; i<num; i++)
        cin >> v[i].X >> v[i].Y;
    
    cin >> dn >> dx;
    ii dpos = conv(dn, dx);
    
    for (auto& [n, x] : v) {    
        if (n == dn) sum += abs(x-dx);
        else if ((n == 1 && dn == 2) || (n == 2 && dn == 1))
            sum += min(x+H+dx, (W-x)+H+(W-dx));
        else if ((n == 3 && dn == 4) || (n == 4 && dn == 3))
            sum += min(x+W+dx, (H-x)+W+(H-dx));
        else {
            ii pos = conv(n, x);
            sum += abs(dpos.X-pos.X)+abs(dpos.Y-pos.Y);
        }
    }
    
    cout<<sum;
    return 0;
}