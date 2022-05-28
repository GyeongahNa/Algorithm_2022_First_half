#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, M, c, qz;
int A[100005];
int B[100005];
deque<int> dq;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++) cin >> A[i];
    for (int i=0; i<N; i++) {
        cin >> B[i];
        if (!A[i]) dq.push_back(B[i]);
    }

    cin >> M;
    for (int i=0; i<M; i++) {
        cin >> c;
        dq.push_front(c);
        cout<<dq.back()<<" ";
        dq.pop_back();
    }
    return 0;
}