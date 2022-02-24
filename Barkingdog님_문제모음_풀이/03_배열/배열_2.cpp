#include <iostream>
using namespace std;

int freq[101] = {};

int func2(int arr[], int N) {

    for (int i=0; i<N; i++) {
        if (freq[100-arr[i]]) return 1;
        freq[arr[i]] = 1;
    }
    return 0; 
}

int main() {

    int arr1[] = {1, 52, 48};
    int arr2[] = {50, 42};
    int arr3[] = {4, 13, 63, 87}; 

    printf("%d\n", func2(arr1, 3));
    printf("%d\n", func2(arr2, 2));
    printf("%d\n", func2(arr3, 4));
    return 0;
}