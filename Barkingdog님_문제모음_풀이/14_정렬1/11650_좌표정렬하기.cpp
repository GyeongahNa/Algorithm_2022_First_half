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
ii input[100005];

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d %d", &input[i].X, &input[i].Y);
    
    sort(input, input+N);

    for (int i=0; i<N; i++)
        printf("%d %d\n", input[i].X, input[i].Y);
    return 0;
}