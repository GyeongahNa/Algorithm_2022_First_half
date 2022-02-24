#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;

int main() {

    int N;
    scanf("%d", &N);
    int total = 2*N-1;

    string line = "";
    for (int i=1; i<=N; i++) {
        int st = 2*i-1;
        for (int j=0; j<(total-st)/2; j++) line += " ";
        for (int j=0; j<st; j++) line += "*";
        line += "\n";
    }

    for (int i=N-1; i>=1; i--) {
        int st = 2*i-1;
        for (int j=0; j<(total-st)/2; j++) line += " ";
        for (int j=0; j<st; j++) line += "*";
        line += "\n";
    }

    printf("%s", line.c_str());
    return 0;
}

