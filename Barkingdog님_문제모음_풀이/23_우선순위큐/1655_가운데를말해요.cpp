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

#define X first
#define Y second

int N;
priority_queue<int> mx;
priority_queue<int, vector<int>, greater<int>> mn;

int main() {

    scanf("%d", &N);
    while (N--) {
        int x;
        scanf("%d", &x);
        if (mn.size() == mx.size()) mx.push(x);
        else mn.push(x);
        if (mn.size() && mx.size() && mn.top() < mx.top()) {
            int tmp = mn.top();
            mn.pop();
            mn.push(mx.top());
            mx.pop();
            mx.push(tmp);
        }
        printf("%d\n", mx.top());
    }
    return 0;
}

/*
최소힙과 최대힙을 사용하여 중간값을 구하는 문제
최소힙에는 큰값들이, 최대힙에는 작은값들이 들어가도록 하여 최대힙의 top에 중간값이 저장되도록 함
*/
