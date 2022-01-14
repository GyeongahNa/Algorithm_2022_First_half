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

char t[4][8];
int K;

void rotate(int n, int dir) {

    if (dir == 1) {
        int tmp = t[n][7];
        for (int i=7; i>0; i--)
            t[n][i] = t[n][i-1];
        t[n][0] = tmp;
    }
    else if (dir == -1) {
        int tmp = t[n][0];
        for (int i=0; i<7; i++)
            t[n][i] = t[n][i+1];
        t[n][7] = tmp;
    }
}

//회전 방향 전파
void go(int x, int dir) {

    int dirs[4] = {};
    dirs[x] = dir;

    //왼쪽으로 전파
    int idx = x;
    while (idx > 0 && t[idx][6] != t[idx-1][2]) {
        dirs[idx-1] = -dirs[idx];
        idx--;
    }

    //오른쪽으로 전파
    idx = x;
    while (idx < 3 && t[idx][2] != t[idx+1][6]) {
        dirs[idx+1] = -dirs[idx];
        idx++;
    }

    for (int i=0; i<4; i++)
        rotate(i, dirs[i]);
}

int main() {

    for (int i=0; i<4; i++) {
        for (int j=0; j<8; j++)
            scanf(" %c", &t[i][j]); 
    }

    scanf("%d", &K);
    while (K--) {
        int n, dir;
        scanf("%d %d", &n, &dir);
        go(n-1, dir);
    }

    int ans = 0;
    for (int i=0; i<4; i++)
        ans += (t[i][0]-'0')*(1<<i);
    printf("%d", ans);
    return 0;
}

// 회전율 전파 방법으로 하면 더 간단히 구현 가능
// void rotate(int n, int dir) {

//     if (dir == 1) {
//         int tmp = t[n][7];
//         for (int i=7; i>0; i--)
//             t[n][i] = t[n][i-1];
//         t[n][0] = tmp;
//     }
//     else if (dir == -1) {
//         int tmp = t[n][0];
//         for (int i=0; i<7; i++)
//             t[n][i] = t[n][i+1];
//         t[n][7] = tmp;
//     }
// }

// int main() {

//     for (int i=0; i<4; i++) {
//         for (int j=0; j<8; j++)
//             scanf(" %c", &t[i][j]); 
//     }

//     scanf("%d", &K);
//     while (K--) {
//         int n, dir;
//         scanf("%d %d", &n, &dir);

//         if (n == 1) {
//             int pole = t[0][2];
//             rotate(0, dir);
//             for (int i=1; i<4; i++) {
//                 if (pole == t[i][6]) break;
//                 pole = t[i][2];
//                 dir *= -1;
//                 rotate(i, dir);
//             }
//         }
//         else if (n == 2) {
//             int pole = t[1][6];
//             if (pole != t[0][2]) rotate(0, -dir);

//             pole = t[1][2];
//             rotate(1, dir);
//             for (int i=2; i<4; i++) {
//                 if (pole == t[i][6]) break;
//                 pole = t[i][2];
//                 dir *= -1;
//                 rotate(i, dir);
//             }
//         }
//         else if (n == 3) {
//             int pole = t[2][2];
//             if (pole != t[3][6]) rotate(3, -dir);

//             pole = t[2][6];
//             rotate(2, dir);
//             for (int i=1; i>=0; i--) {
//                 if (pole == t[i][2]) break;
//                 pole = t[i][6];
//                 dir *= -1;
//                 rotate(i, dir);
//             }
//         }
//         else if (n == 4) {
//             int pole = t[3][6];
//             rotate(3, dir);
//             for (int i=2; i>=0; i--) {
//                 if (pole == t[i][2]) break;
//                 pole = t[i][6];
//                 dir *= -1;
//                 rotate(i, dir);
//             }
//         }
//     }

//     int ans = 0;
//     for (int i=0; i<4; i++)
//         ans += (t[i][0]-'0')*(1<<i);
//     printf("%d", ans);
//     return 0;
// }