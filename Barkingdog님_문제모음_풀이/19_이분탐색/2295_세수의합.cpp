#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <limits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second


int N;
int A[1005];
int two[1000005];
int mx;

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &A[i]);

    int idx = 0;
    for (int i=0; i<N; i++) { //가능한 두 수의 합 구하기
        for (int j=0; j<N; j++) 
            two[idx++] = A[i]+A[j];
    }
    sort(two, two+idx);

    for (int i=0; i<N; i++) { //세 수의 합
        for (int j=0; j<N; j++) { //한 개의 수
            int left = A[i]-A[j]; // 나머지 두 수 
            if (binary_search(two, two+idx, left)) //나머지 두 수가 가능 목록에 있는지 확인
                mx = max(mx, A[i]);
        }
    }

    printf("%d", mx);
    return 0;
}

/*
O(N^4): 세 수의 수를 모두 for문으로 순회+배열에 세 수의 합이 있는지 선형탐색으로 확인
O(N^3logN): 세 수의 수를 모두 for문으로 순회+배열에 세 수의 합이 있는지 이분탐색으로 확인
O(N^2logN): 세 수의 합에서 한개의 수를 뺀 나머지가 미리 만들어놓은 두 수의 합 목록에 있는지 확인
*/