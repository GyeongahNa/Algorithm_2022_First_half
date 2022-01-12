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

/*next premutation()으로 푸는 방법 공부하기*/

int N;
int d[20];
int arr[20];
int isused[20];

void func(int k) {

    if (k == 6) {
        for (int i=0; i<6; i++)
            printf("%d ", d[arr[i]]);
        printf("\n");
        return ;
    }

    int st = 0;
    if (k != 0) st = arr[k-1]+1;
    for (int i=st; i<N; i++) {
        if (isused[i]) continue;
        arr[k] = i;
        isused[i] = 1;
        func(k+1);
        isused[i] = 0;
    }
}

int main() {

    while (true) {
        
        scanf("%d", &N);
        if (N == 0) break;
        for (int i=0; i<N; i++)
            scanf("%d", &d[i]);
        memset(isused, 0, sizeof(isused));
        func(0);
        printf("\n");
    }
    return 0;
}