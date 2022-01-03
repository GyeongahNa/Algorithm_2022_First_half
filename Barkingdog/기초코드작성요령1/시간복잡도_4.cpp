#include <iostream>
#include <cmath>

using namespace std;

//O(logN)
int func4(int N) {

    int val = 1;
    while (2*val <= N) {
        val *= 2;
    }
    return val;
}

int main() {

    int N;
    scanf("%d", &N);
    printf("%d", func4(N));
    return 0;
}