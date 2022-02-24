#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;

char func(int cnt) {
    
    if (cnt == 1) return 'A';
    if (cnt == 2) return 'B';
    if (cnt == 3) return 'C';
    if (cnt == 4) return 'D';
    if (cnt == 0) return 'E';
    return 'F';
}

int main() {

    for (int i=0; i<3; i++) {

        int n, cnt = 0;
        for (int i=0; i<4; i++) {
            scanf("%d", &n);
            if (n == 0) cnt++;
        }
        printf("%c\n", func(cnt));
    }
    return 0;
}