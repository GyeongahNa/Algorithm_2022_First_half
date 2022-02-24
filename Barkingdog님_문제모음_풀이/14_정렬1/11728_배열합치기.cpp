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

int N, M;
int A[1000005];
int B[1000005];
int res[2000005];

void sort() {
    
    int i = 0, j = 0;
    for (int k=0; k<N+M; k++) {
        if (i >= N) res[k] = B[j++];
        else if (j >= M) res[k] = A[i++];
        else if (A[i] > B[j]) res[k] = B[j++];
        else res[k] = A[i++];
    }
    
}

void printarr() {

    for (int i=0; i<N+M; i++)
        cout<<res[i]<<" ";
    cout<<endl;
}

int main() {

    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++)
        scanf("%d", &A[i]);
    for (int i=0; i<M; i++)
        scanf("%d", &B[i]);

    sort();
    printarr();
    return 0;
}