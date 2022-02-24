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
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
int map[200][200];
int cnt[2];

void func(int x, int y, int size) {

    bool check = true;
    for (int i=x; i<x+size; i++) {
        for (int j=y; j<y+size; j++) {
            if (map[i][j] != map[x][y]) {
                check = false;
                break;
            }
        }
    }

    if (check) {
        cnt[map[x][y]]++;
        return ;
    }

    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            func(x+i*size/2, y+j*size/2, size/2);
        }
    }
    return ;
}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            scanf("%d", &map[i][j]);
    }

    func(0, 0, N);
    printf("%d\n%d\n", cnt[0], cnt[1]);
    return 0;
}