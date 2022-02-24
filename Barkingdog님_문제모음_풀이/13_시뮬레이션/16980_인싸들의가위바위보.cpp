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

#define X first
#define Y second

int N, K;
int A[15][15];
int act[3][25];
int isused[15];

int re;

int getWinner(int a, int i, int b, int j) {

    int res1 = act[a][i]; 
    int res2 = act[b][j]; 
    if (A[res1][res2] == 2 || (A[res1][res2] == 1 && a > b)) return a;
    return b;
}

void play() { 

    int t = 0;
    int idx[3] = {0, 0, 0};
    int cnt[3] = {};
    int winner = 0;
    int p1 = 0, p2 = 2;
    
    while (idx[0] < N) {

        if (p1 == winner) p2 = 3-winner-p2;
        else p1 = 3-winner-p1;

        winner = getWinner(p1, idx[p1], p2, idx[p2]); 
        idx[p1]++;
        idx[p2]++;
        cnt[winner]++;
        if (cnt[winner] >= K) {
            if (winner == 0) re = 1;
            break;
        }
    }
}

void func(int k) {

    if (k == N) {
        play();
        return ;
    }

    for (int i=1; i<=N; i++) {
        if (isused[i]) continue;
        act[0][k] = i;
        isused[i] = 1;
        func(k+1);
        isused[i] = 0;
    }

}

int main() {

    scanf("%d %d", &N, &K);
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) 
            scanf("%d", &A[i][j]);
    }
    for (int i=0; i<20; i++)
        scanf("%d", &act[1][i]);
    for (int i=0; i<20; i++) 
        scanf("%d", &act[2][i]);

    func(0);
    printf("%d", re);
    return 0;
}

/*전반적인 로직은 어렵지 않았으나 디테일에서 문제 이해가 어려웠다*/
/*
1) 가위바위보를 할 때, 순서가 지우-경희-민호가 된다 함은, 제일 처음 지우와 경희의 가위바위보로 시작하여 이전의 게임에서 이긴 사람과 이전에 참여하지 않았던 사람의 가위바위보로 이어진다는 의미이다. 지우와 경희가 가위바위보를 하여 지우가 이겼다면, 이후에는 지우 - 민호의 가위바위보로 이어지고, 여기서 민호가 이겼다면, 민호 - 경희의 가위바위보로 이어진다.
2) 한 사람이 이번 판에서 무엇을 낼지 결정할 때, 입력 받은 배열의 각 요소를 건너뛰지 않고 순서대로 사용해야 한다. 
3) 승수가 K가 되면, 게임이 종료된다. 이 때, 지우가 이기는 게임이 아니더라도 다른 사람의 승수가 K 이상이면 게임이 종료된다. */