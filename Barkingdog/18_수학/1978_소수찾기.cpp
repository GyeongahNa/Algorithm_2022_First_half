#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, cnt;

bool isPrime(int x) {
    if (x == 1) return false;
    for (int i=2; i*i<=x; i++) {
        if (!(x%i)) return false;
    }
    return true;
}

int main() {

    scanf("%d", &N);
    while (N--) {
        int x;
        scanf("%d", &x);
        if (isPrime(x)) cnt++;
    }
    printf("%d", cnt);
    return 0;
}