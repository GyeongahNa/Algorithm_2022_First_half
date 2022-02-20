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
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
long long cnt;
vector<long long> A, B, C, D;
vector<long long> two1, two2;

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        long long a, b, c, d;
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        D.push_back(d);
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            two1.push_back(A[i]+B[j]);
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            two2.push_back(C[i]+D[j]);
    }

    sort(two1.begin(), two1.end());
    sort(two2.begin(), two2.end());

    for (int i=0; i<two1.size(); i++)
        cnt += upper_bound(two2.begin(), two2.end(), -two1[i])-lower_bound(two2.begin(), two2.end(), -two1[i]);
    printf("%lld", cnt);
    return 0;
}

/*sorting하는 과정 잊지 말기*/