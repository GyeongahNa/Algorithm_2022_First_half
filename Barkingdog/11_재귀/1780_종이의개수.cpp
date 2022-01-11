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
int cnt[3];
int map[3000][3000];

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
        cnt[map[x][y]+1]++;
        return ;
    }

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            func(x+i*size/3, y+j*size/3, size/3);
        }
    }
    return ;
}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++)
            scanf("%d", &map[i][j]);
    }

    func(0, 0, N);
    printf("%d\n%d\n%d\n", cnt[0], cnt[1], cnt[2]);
    return 0;
}