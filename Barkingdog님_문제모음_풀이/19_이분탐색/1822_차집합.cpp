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

int NA, NB;
int A[500005];
int B[500005];
vector<int> v;

int main() {

    scanf("%d %d", &NA, &NB);
    for (int i=0; i<NA; i++) scanf("%d", &A[i]);
    for (int i=0; i<NB; i++) scanf("%d", &B[i]);
    sort(A, A+NA);
    sort(B, B+NB);

    for (int i=0; i<NA; i++) {
        if (!binary_search(B, B+NB, A[i])) 
            v.push_back(A[i]);
    }
    
    printf("%d\n", (int)v.size());
    for (int i=0; i<v.size(); i++) 
        printf("%d ", v[i]);
    return 0;
}