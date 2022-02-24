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

int N;

int main() {

    scanf("%d", &N);

    for (int i=2; i*i<=N; i++) {
        while (N%i == 0) {
            N /= i;
            printf("%d\n", i);
        }
    }
    if (N != 1) printf("%d\n", N);
    return 0;
}

/*산술의 기본 정리
각 자연수를 소수들의 곱으로 표현하는 방법은 1가지로 유일함*/