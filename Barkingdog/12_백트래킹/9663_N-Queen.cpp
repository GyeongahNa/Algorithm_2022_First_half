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

int N, cnt;

int isused1[40];
int isused2[40];
int isused3[40];

void func(int cur) {

    if (cur == N) {
        cnt++;
        return ;
    }

    for (int i=0; i<N; i++) {
        if (isused1[i] || isused2[cur+i] || isused3[cur-i+N-1]) continue;
        isused1[i] = 1;
        isused2[cur+i] = 1;
        isused3[cur-i+N-1] = 1;
        func(cur+1);
        isused1[i] = 0;
        isused2[cur+i] = 0;
        isused3[cur-i+N-1] = 0;
    }
}

int main() {

    scanf("%d", &N);
    func(0);
    printf("%d", cnt);
    return 0;
}