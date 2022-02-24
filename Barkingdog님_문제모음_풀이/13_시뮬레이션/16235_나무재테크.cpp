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
#define MX 2147483640

int N, M, K;
vector<int> tree[15][15];
int vita[15][15];
int A[15][15];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

/* 반복문을 도는 와중에 tree[i][j]의 원소를 erase 해버리면, 배열이 계속 바뀌어 연산 오류*/
/* 다른 임시 배열을 만들어서 남아있는 나무를 추가해준뒤, 맨 마지막에 tree[i][j] 교체*/
void ss() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (!tree[i][j].size()) continue;
    
            int add = 0;
            vector<int> tmp;
            sort(tree[i][j].begin(), tree[i][j].end());
            for (int k=0; k<tree[i][j].size(); k++) {
                if (vita[i][j] >= tree[i][j][k]) {
                    vita[i][j] -= tree[i][j][k];
                    tmp.push_back(tree[i][j][k]+1);
                    continue;
                }
                add += tree[i][j][k]/2;
            }
            tree[i][j].clear();
            for (int k=0; k<tmp.size(); k++)
                tree[i][j].push_back(tmp[k]);
            vita[i][j] += add;
        }
    }
}

void fall() {

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {    
            for (int k=0; k<tree[i][j].size(); k++) {
                if (tree[i][j][k]%5) continue;
                for (int l=0; l<8; l++) {
                    int nx = i+dx[l];
                    int ny = j+dy[l];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    tree[nx][ny].push_back(1);
                }
            }
        }
    }
}

void winter() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            vita[i][j] += A[i][j];
    }
}

int main() {

    scanf("%d %d %d", &N, &M, &K);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &A[i][j]);
            vita[i][j] = 5;
        }
    }

    for (int i=0; i<M; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        tree[x-1][y-1].push_back(z); 
    }

    while (K--) {
        ss();
        fall();
        winter();
    }

    int cnt = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            cnt += tree[i][j].size();
    }
    printf("%d", cnt);
    return 0;
}