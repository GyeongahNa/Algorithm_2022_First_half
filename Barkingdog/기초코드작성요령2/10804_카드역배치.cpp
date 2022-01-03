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

// STL reverse() 
int arr[20];

void swap(int &a, int &b) {

    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    
    for (int i=0; i<20; i++)
        arr[i] = i+1;
    
    int a, b;
    for (int i=0; i<10; i++) {
        scanf("%d %d", &a, &b);
        for (int j=0; j<=(b-a)/2; j++)
            swap(arr[a+j-1], arr[b-j-1]);
    }

    for (int i=0; i<20; i++)
        printf("%d ", arr[i]);
    return 0;
}