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
using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;

ll N, M, sum;
ll minB = pow(10, 18);
bool valid = true;

ll gcd(ll a,  ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    while (N--) {
        ll a, b;
        cin >> a >> b;

        if (a > 0 || sum+a >= 0) {
            sum += a;
            if (sum != b) valid = false;
        }
        else {
            M = gcd(b-sum-a, M);
            sum = b;
            if (b) minB = min(minB, b);
            if (M <= minB && minB != pow(10, 18)) valid = false;
        }
    }

    if (valid && M) cout<<M;
    else if (valid && !M) cout<<1;
    else cout<<-1;
    return 0;
}