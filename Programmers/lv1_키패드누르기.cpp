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
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second
#define INF 1000
#define STAR 10
#define SHARP 11

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


void Floyd(vector<vector<int>>& keypad, vector<vector<int>>& dist) {
    
    for (int i=0; i<12; i++) dist[i][i] = 0;
    for (int i=0; i<4; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<4; k++) {
                int nx = i+dx[k];
                int ny = j+dy[k];
                if (nx < 0 || nx >= 4 || ny < 0 || ny >= 3) continue;
                dist[keypad[i][j]][keypad[nx][ny]] = 1;
            }
        }
    }
    
    for (int k=0; k<12; k++) {
        for (int i=0; i<12; i++) {
            for (int j=0; j<12; j++)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
        }
    }
}


string solution(vector<int> numbers, string hand) {
    
    vector<vector<int>> keypad = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 0, 11}};
    vector<vector<int>> dist(12, vector<int>(12, INF));
    
    Floyd(keypad, dist);
    
    string ret = "";
    int left = STAR, right = SHARP;
    for (auto x : numbers) {
        if (x == 1 || x == 4 || x == 7) {
            ret += "L";
            left = x;
            continue;
        }
        if (x == 3 || x == 6 || x == 9) {
            ret += "R";
            right = x;
            continue;
        }
        if (dist[left][x] == dist[right][x] && hand == "left") {
            ret += "L";
            left = x;
            continue;
        }
        if (dist[left][x] == dist[right][x] && hand == "right") {
            ret += "R";
            right = x;
            continue;
        }
        if (dist[left][x] < dist[right][x]) {
            ret += "L";
            left = x;
            continue;
        }
        ret += "R";
        right = x;
    }

    return ret;
}