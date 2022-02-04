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

int N = 10;
int d = 3;
int p10[3];
int arr[10] = {012, 421, 046, 674, 103, 502, 007, 100, 021, 545};

vector<int> v[10];

int digitNum(int x, int a) {
    return x/p10[a]%10;
}

int radixSort() {

    p10[0] = 1;
    for (int i=1; i<d; i++) p10[i] = p10[i-1]*10;

    for (int i=0; i<d; i++) {
        for (int j=0; j<10; j++) v[j].clear();
        for (int j=0; j<N; j++)
            v[digitNum(arr[j], i)].push_back(arr[j]);

        int arridx = 0;
        for (int j=0; j<10; j++) {
            for (int k=0; k<v[j].size(); k++)
                arr[arridx++] = v[j][k];
        }
    }
}

void printarr() {

    for (int i=0; i<N; i++)
        printf("%d\n", arr[i]);
}

int main() {

    radixSort();
    printarr();
    return 0;
}