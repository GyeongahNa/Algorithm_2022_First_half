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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int N;
int freq[2000005];

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        freq[x+1000000]++;
    }

    for (int i=0; i<=2000000; i++) {
        if (!freq[i]) continue;
        for (int j=0; j<freq[i]; j++)
            printf("%d\n", i-1000000);
    } 
}

/*counting sort*/