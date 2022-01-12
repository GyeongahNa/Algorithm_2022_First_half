#include <cstdio>
#include <cstring>
#include <cmath>
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

int N;
int t, S;
int cnt;
int d[30];

void func(int cur) {

    if (cur == N) {
        if (t == S) cnt++;
        return ;
    }

    func(cur+1);
    t += d[cur];
    func(cur+1);
    t -= d[cur];
}

int main() {

    scanf("%d %d", &N, &S);
    for (int i=0; i<N; i++)
        scanf("%d", &d[i]);

    func(0);
    if (S == 0) cnt--;
    printf("%d", cnt);
    return 0;
}