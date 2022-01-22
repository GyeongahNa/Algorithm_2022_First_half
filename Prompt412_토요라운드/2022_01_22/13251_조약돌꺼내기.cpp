#include <cstring>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <queue>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int M;
double n[55];
int K;

int main() {
    
    scanf("%d", &M);
    
    double t = 0;
    for (int i=0; i<M; i++) {
        scanf("%lf", &n[i]);
        t += n[i];
    }
    scanf("%d", &K);

    double re = 0;
    for (int i=0; i<M; i++) {
        if (n[i] < K) continue;

        double tmp = 1;
        for (int j=0; j>=-K+1; j--)
            tmp *= (n[i]+j)/(t+j);

        re += tmp;
    }

    printf("%.15f", re);
    return 0;
}