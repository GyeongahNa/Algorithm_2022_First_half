#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int M, N;
vector<bool> vcheck(1000005, true);

int main() {

    scanf("%d %d", &M, &N);

    vcheck[1] = false;
    for (int i=2; i*i<=N; i++) {
        if (!vcheck[i]) continue;
        for (int j=i*i ; j<=N; j+=i) 
            vcheck[j] = false;
    }

    for (int i=M; i<=N; i++) {
        if (!vcheck[i]) continue;
        printf("%d\n", i);
    }
    return 0;
}

/*에스토스테네스의 체 최적화
i의 배수를 지우기 위해서는 i*i부터 확인하면 됨*/