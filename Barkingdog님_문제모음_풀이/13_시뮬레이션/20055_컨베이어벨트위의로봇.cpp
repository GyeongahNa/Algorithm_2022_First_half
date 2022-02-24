#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <queue>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, K;
int robot[105]; // 0 ~ N-1
int A[205]; // 0 ~ 2*N-1


void rotateRobot() {

    for (int i=N-1; i>0; i--) 
        robot[i] = robot[i-1];
    robot[0] = 0;
}

void rotateA() {

    int tmp = A[2*N-1];
    for (int i=2*N-1; i>0; i--) 
        A[i] = A[i-1];
    A[0] = tmp;
}

void moveRobot() {

    robot[N-1] = 0;
    for (int i=N-2; i>=0; i--) {
        if (!robot[i]) continue;
        if (robot[i+1]) continue;
        if (A[i+1] < 1) continue;
        robot[i+1] = 1;
        robot[i] = 0;
        A[i+1]--;
    }
}

void addRobot() {

    if (A[0] < 1) return; // robot[0]에 로봇이 있을 경우를 생각해봤으나 딱히 언급은 없어서 예외처리 하지 않음
    robot[0]++;
    A[0]--;
}

bool check() {

    int cnt = 0;
    for (int i=0; i<2*N; i++) {
        if (!A[i]) cnt++;
    }
    return cnt >= K;
}   

int main() {

    scanf("%d %d", &N, &K);
    for (int i=0; i<2*N; i++)
        scanf("%d", &A[i]);

    int step = 1;
    while (1) {
        rotateRobot();
        rotateA();
        moveRobot();
        addRobot();
        if (check()) break;
        step++;
   }
    printf("%d", step);
    return 0;
}