#include <vector>
#include <iostream>
using namespace std;

//중복 순열: 순서 O, 중복 O
//nπr = n^r

#define n 3
#define r 2

int arr[30];

void printarr() {

    for (int i=0; i<r; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

void permutationWithRep(int k) {

    if (k == r) {
        printarr();
        return ;
    }

    for (int i=0; i<n; i++) {
        arr[k] = i;
        permutationWithRep(k+1);
    }
}

int main() {

    permutationWithRep(0);
    return 0;
}