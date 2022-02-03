#include <iostream>
using namespace std;

int n = 10;
int arr[10] = {30, 10, 60, 50, 40, 90, 20, 70, 80, 0};
int tmp[10];

void merge(int st, int en) {

    int mid = (st+en)/2;
    int i = st, j = mid;
    for (int k=st; k<en; k++) {
        if (i >= mid) tmp[k] = arr[j++];
        else if (j >= en) tmp[k]= arr[i++];
        else if (arr[i] <= arr[j]) tmp[k] = arr[i++]; //stable sort
        else tmp[k] = arr[j++];
    }

    for (int k=st; k<en; k++) arr[k] = tmp[k];
}

void mergeSort(int st, int en) {

    if (en == st+1) return ;
    int mid = (st+en)/2;
    mergeSort(st, mid);
    mergeSort(mid, en);
    merge(st, en);
}

void printarr() {

    for (int i=0; i<n; i++) 
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {

    mergeSort(0, n);
    printarr();
    return 0;
}

/*stable sort: 정렬시 두 원소가 같은 경우 원래의 순서를 따르는 것*/