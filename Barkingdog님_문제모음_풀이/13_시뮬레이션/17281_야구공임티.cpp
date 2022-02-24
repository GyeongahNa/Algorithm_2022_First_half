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

int N;
int act[55][9];
int arr[9];
int isused[9];
int ans;

int getScore() {

    int score = 0, p = 0;
     for (int i=0; i<N; i++) { //이닝

        int s[3] = {};
        int outcnt = 0;
        while (outcnt < 3) {
            
            int re = act[i][arr[p]];
            p = (p+1)%9;
            if (re == 0) outcnt++;
            else if (re == 4) {
                for (int j=0; j<3; j++) {
                    if (s[j]) score++;
                    s[j] = 0;
                }
                score++;
            }
            else {
                for (int j=2; j>=0; j--) {
                    if (!s[j]) continue;
                    if (j+re >= 3) score++;
                    else s[j+re] = s[j];
                    s[j] = 0;
                }
                s[re-1] = 1;
            }
        }

    }

    return score;
}

void func(int k) { 

    if (k == 9) {
        ans = max(ans, getScore());
        return ;
    }

    if (k == 3) {
        arr[3] = 0;
        func(k+1);
        return ;
    }

    for (int i=1; i<9; i++) {
        if (isused[i]) continue;
        arr[k] = i;
        isused[i] = 1;
        func(k+1);
        isused[i] = 0;
    }

}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<9; j++)
            scanf("%d", &act[i][j]);
    }

    func(0);
    printf("%d", ans);
    return 0;
}