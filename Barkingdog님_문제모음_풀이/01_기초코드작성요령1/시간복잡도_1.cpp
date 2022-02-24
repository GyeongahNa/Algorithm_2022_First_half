#include <iostream>
using namespace std;

int func1(int N) {
    
    int sum = 0;
    for (int i=1; i<=N; i++) {
        if (i % 3 == 0 || i % 5 == 0) sum += i;
    }
    return sum;
}

int main() {

    int N;
    scanf("%d", &N);
    printf("%d", func1(N));
    return 0;
}

