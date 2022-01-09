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

int main() {
    int N;
    scanf("%d", &N);

    queue<int> q;
    for (int i=1; i<=N; i++)
        q.push(i);
    
    int act = -1;
    while (q.size() > 1) {
        if (act == -1) q.pop();
        else {
            q.push(q.front());
            q.pop();
        }
        act *= -1;
    }
    printf("%d", q.front());
    return 0;
}