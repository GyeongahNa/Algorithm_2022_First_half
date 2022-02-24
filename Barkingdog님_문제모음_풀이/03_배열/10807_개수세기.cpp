#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int freq[201] = {};
int N, V;

int main() {

    scanf("%d", &N);
    for (int i = 0; i<N; i++) {
        int a;
        scanf("%d", &a);
        freq[a+100]++;
    } // while (N--) 로 변경하는 것이 더 효율적
    
    scanf("%d", &V);
    printf("%d", freq[V+100]);
    return 0;
}