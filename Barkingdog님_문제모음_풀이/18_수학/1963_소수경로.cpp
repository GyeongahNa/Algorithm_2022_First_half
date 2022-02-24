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

int T;
int P10[5];
int dist[10000];
vector<bool> check(10000, true);


void eratosthenes() {

    check[1] = false;
    for (int i=2; i*i<=9999; i++) {
        if (!check[i]) continue;
        for (int j=i*i; j<=9999; j+=i)
            check[j] = false;
    }
}


void setPower() {

    P10[0] = 1;
    for (int i=1; i<=4; i++) 
        P10[i] = P10[i-1]*10;
}


int convert(int cur, int i, int j) {
    return cur/P10[i+1]*P10[i+1]+j*P10[i]+cur%P10[i];
}


void bfs(int s, int e) {

    memset(dist, -1, sizeof(dist));

    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        for (int i=3; i>=0; i--) { //4자리 바꾸기
            for (int j=0; j<=9; j++) { //각 자리는 0~9까지로 교환 가능
                if (i == 3 && j == 0) continue;
                int newn = convert(cur, i, j);
                if (!check[newn] || dist[newn] != -1) continue; //소수가 아니거나 이미 방문한적 있다면 패스
                q.push(newn);
                dist[newn] = dist[cur]+1;
            }
        }
    }
}


int main() {
    
    eratosthenes(); //소수 판별해 놓기
    setPower();  //10의 제곱수 구해놓기

    scanf("%d", &T);
    while (T--) {
        int s, e;
        scanf("%d %d", &s, &e);
        bfs(s, e); //최단거리 구하기
        if (dist[e] == -1) printf("Impossible\n");
        else printf("%d\n", dist[e]);
    }
    return 0;
}