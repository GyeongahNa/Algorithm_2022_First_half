#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int N;
vector<vector<int>> dist1(25, vector<int>(25, 0));
vector<vector<int>> dist2(25, vector<int>(25, 0));

int main() {

    cin >> N;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> dist1[i][j];
            dist2[i][j] = dist1[i][j];
        }
    }

    for (int k=1; k<=N; k++) {
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                if (k == i || k == j) continue;
                if (dist1[i][j] > dist1[i][k]+dist1[k][j]) {
                    cout << "-1";
                    return 0;
                }
                if (dist1[i][j] == dist1[i][k]+dist1[k][j]) dist2[i][j] = 0;
            }
        }
    }

    int tot = 0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++)
            tot += dist2[i][j];
    }
    cout << tot/2;
    return 0;
}

/* 
dist1[i][j] > dist[i][k]+dist[k][j] 인 경우: 불가능한 상황이므로 -1 출력
dist1[i][j] == dist[i][k]+dist[k][j] 인 경우: 돌아서 최소 거리로 도달한 상황이므로 정점 i와 정점 j 사이의 간선을 없앰
*/