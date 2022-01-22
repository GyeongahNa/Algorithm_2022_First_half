#include <cstring>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <queue>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int green[6][4];
int blue[4][6];

void moveGreen(int t, int x, int y) {

    //t == 1 (x, y)
    //t == 2 (x, y), (x, y+1)
    //t == 3 (x, y), (x-1, y)

    x = -1;
    while (1) {
        int nx = x+1;
        if (nx >= 6) break;
        if (green[nx][y]) break;
        if (t == 2 && green[nx][y+1]) break;
        x = nx;
    }

    green[x][y] = 1;
    if (t == 2) green[x][y+1] = 1;
    else if (t == 3) green[x-1][y] = 1;
}

void moveBlue(int t, int x, int y) {

    // t == 1 (x, y)
    // t == 2 (x, y-1), (x, y)
    // t == 3 (x, y), (x+1, y)

    y = -1;
    while (1) {
        int ny =y+1;
        if (ny >= 6) break;
        if (blue[x][ny]) break;
        if (t == 3 && blue[x+1][ny]) break;
        y = ny;
    }

    blue[x][y] = 1;
    if (t == 2) blue[x][y-1] = 1;
    else if (t == 3) blue[x+1][y] = 1;
}

void putForward(int row) {

    for (int i=row; i>0; i--) {
        for (int j=0; j<4; j++)
            green[i][j] = green[i-1][j];
    }

    for (int j=0; j<4; j++)
        green[0][j] = 0;
}

int eraseGreen() {

    int cnt = 0;
    for (int i=0; i<6; i++) {
        int check = 1;
        for (int j=0; j<4; j++) {
            if (green[i][j]) continue;
            check = 0;
            break;
        }
        if (check == 1) {
            cnt++;
            for (int j=0; j<4; j++)
                green[i][j] = 0;
            putForward(i);
        }
    }
    return cnt;
}

void pullAside(int col) {

    for (int i=col; i>0; i--) {
        for (int j=0; j<4; j++)
            blue[j][i] = blue[j][i-1];
    }

    for (int i=0; i<4; i++)
        blue[i][0] = 0;
}

int eraseBlue() {

    int cnt = 0;
    for (int i=0; i<6; i++) {
        int check = 1;
        for (int j=0; j<4; j++) {
            if (blue[j][i]) continue;
            check = 0;
            break;
        }
        if (check == 1) {
            cnt++;
            for (int j=0; j<4; j++)
                blue[j][i] = 0;
            pullAside(i);
        }
    }
    return cnt;
}

void specialGreen() {

    int cntLine = 0;
    for (int i=0; i<2; i++) {
        int check = 0;
        for (int j=0; j<4; j++) {
            if (!green[i][j]) continue;
            check = 1;
            break;
        }
        if (check) cntLine++;
    }
    
    for (int i=0; i<cntLine; i++) {
        for (int j=0; j<4; j++)
            green[5][j] = 0;
        putForward(5);
    }
}

void specialBlue() {

    int cntLine = 0;
    for (int i=0; i<2; i++) {
        int check = 0;
        for (int j=0; j<4; j++) {
            if (!blue[j][i]) continue;
            check = 1;
            break;
        }
        if (check) cntLine++;
    }

    for (int i=0; i<cntLine; i++) {
        for (int j=0; j<4; j++)
            blue[j][5] = 0;
        pullAside(5);
    }
}

int main() {

    int N;
    scanf("%d", &N);

    int score = 0;

    while (N--) {
        int t, x, y;
        scanf("%d %d %d", &t, &x, &y);
        moveGreen(t, x, y);
        moveBlue(t, x, y);
        score += eraseGreen();
        score += eraseBlue();
        specialGreen();
        specialBlue();
    }
    
    int n = 0;
    for (int i=0; i<6; i++) {
        for (int j=0; j<4; j++) {
            if (green[i][j]) n++;
            if (blue[j][i]) n++;
        }
    }

    printf("%d\n", score);
    printf("%d\n", n);
    return 0;
}