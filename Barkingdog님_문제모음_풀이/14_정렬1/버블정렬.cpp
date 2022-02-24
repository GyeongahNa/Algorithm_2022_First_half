#include <iostream>
using namespace std;

int n = 10;
int arr[10] = {30, 10, 60, 50, 40, 90, 20, 70, 80, 0};

void bubbleSort() {

    for (int i=0; i<n; i++) {
        for (int j=0; j<n-1-i; j++) {
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

void printarr() {

    for (int i=0; i<n; i++) 
        cout<<arr[i]<<" ";
    cout<<endl;
}


int main() {

    bubbleSort();
    printarr();
    return 0;
}
