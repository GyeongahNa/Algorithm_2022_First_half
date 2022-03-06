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
using ss = pair<string, string>;

#define X first
#define Y second
#define INF 1000000000

int N, R, M, K, sz;
vector<vector<int>> dist1(105, vector<int>(105, INF));
vector<vector<int>> dist2(105, vector<int>(105, INF));

map<string, int> city;
vector<int> visited;


int discnt(string type, int cost) {

    if (type == "Mugunghwa" || type == "ITX-Saemaeul" || type == "ITX-Cheongchun") return 0;
    if (type == "S-Train" || type == "V-Train") return cost;
    return cost*2;
}

void getInput() {

    cin >> N >> R;
    while (N--) {
        string name;
        cin >> name;
        if (city.find(name) != city.end()) continue;
        city.insert({name, ++sz});
    }

    for (int i=1; i<=sz; i++) {
        dist1[i][i] = 0;
        dist2[i][i] = 0;
    }

    cin >> M;
    while (M--) {
        string name;
        cin >> name;
        visited.push_back(city[name]);
    }

    cin >> K;
    while (K--) {
        
        string type, S, E;
        int cost;
        cin >> type >> S >> E >> cost;

        int n1 = city[S], n2 = city[E];

        dist1[n1][n2] = min(dist1[n1][n2], cost*2);
        dist1[n2][n1] = min(dist1[n2][n1], cost*2);

        cost = discnt(type, cost);
        dist2[n1][n2] = min(dist2[n1][n2], cost);
        dist2[n2][n1] = min(dist2[n2][n1], cost);
    }
}

void Floyd() {

    for (int k=1; k<=sz; k++) {
        for (int i=1; i<=sz; i++) {
            for (int j=1; j<=sz; j++) {
                dist1[i][j] = min(dist1[i][j], dist1[i][k]+dist1[k][j]);
                dist2[i][j] = min(dist2[i][j], dist2[i][k]+dist2[k][j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    getInput();
    Floyd();

    int tot1 = 0, tot2 = 2*R;
    for (int i=1; i<visited.size(); i++) {
        tot1 += dist1[visited[i-1]][visited[i]];
        tot2 += dist2[visited[i-1]][visited[i]];
    }

    if (tot1 > tot2) cout<<"Yes";
    else cout<<"No";
    return 0;
}