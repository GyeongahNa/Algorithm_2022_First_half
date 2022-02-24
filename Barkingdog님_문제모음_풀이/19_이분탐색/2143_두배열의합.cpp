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

int T, N, M;
long long cnt;
vector<int> A, B;
vector<int> sumA, sumB;

void getSum(vector<int> v, vector<int>& vsum) {

    for (int i=1; i<=v.size(); i++) {
        int st = 0, en = i, sum = 0;
        for (int j=st; j<en; j++) sum += v[j];
        while (en <= v.size()) {
            vsum.push_back(sum);
            sum -= v[st++];
            sum += v[en++];
        }
    }
}

int main() {

    scanf("%d\n%d", &T, &N);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        A.push_back(x);
    }
    
    scanf("%d", &M);
    for (int i=0; i<M; i++) {
        int x;
        scanf("%d", &x);
        B.push_back(x);
    }

    getSum(A, sumA);
    getSum(B, sumB);
    sort(sumB.begin(), sumB.end());

    for (int i=0; i<sumA.size(); i++) {
        int left = T-sumA[i];
        cnt += upper_bound(sumB.begin(), sumB.end(), left)-lower_bound(sumB.begin(), sumB.end(), left);
    }
    printf("%lld", cnt);
    return 0;
}