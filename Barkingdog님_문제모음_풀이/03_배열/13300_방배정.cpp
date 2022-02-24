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

int N, K;
int freq[2][6];

int main() {

    scanf("%d %d", &N, &K);
    
    while (N--) {
        int s, y;
        scanf("%d %d", &s, &y);
        freq[s][y-1]++;
    }

    int cnt = 0;
    for (int i=0; i<2; i++) {
        for (int j=0; j<6; j++)
            cnt += (freq[i][j]+K-1)/K;
    }
    printf("%d", cnt);
    return 0;
}