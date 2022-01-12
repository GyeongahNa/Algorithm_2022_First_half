#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, re;
ii egg[20];
int broken[20];

void func(int k, int total) {

    if (k == N) {
        re = max(re, total);
        return ;
    }

    bool check = false;
    for (int i=0; i<N; i++) {
        if (i != k && !broken[i]) {
            check = true;
            break;
        }
    }

    if (broken[k] || !check) func(k+1, total);
    else {
        for (int i=0; i<N; i++) {
            if (i == k || broken[i]) continue;

            int newtotal = total;
            egg[k].X -= egg[i].Y;
            egg[i].X -= egg[k].Y;

            if (egg[k].X <= 0) {
                broken[k] = 1;
                newtotal++;
            }
            if (egg[i].X <= 0) {
                broken[i] = 1;
                newtotal++;
            }

            func(k+1, newtotal);
            egg[k].X += egg[i].Y;
            egg[i].X += egg[k].Y;
            broken[k] = 0;
            broken[i] = 0;
        }
    }
}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d %d", &egg[i].X, &egg[i].Y);

    func(0, 0);
    printf("%d", re);
    return 0;
}