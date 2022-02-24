#include <iostream>
using namespace std;

int N;
int arr[1005];
int tmp[1005];

void merge(int st, int en) {

    int mid = (st+en)/2;
    int i = st; int j = mid;
    for (int k=st; k<en; k++) {
        if (i >= mid) tmp[k] = arr[j++];
        else if (j >= en) tmp[k] = arr[i++];
        else if (arr[i] <= arr[j]) tmp[k] = arr[i++];
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

    for (int i=0; i<N; i++)
        cout<<arr[i]<<endl;
}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &arr[i]);

    mergeSort(0, N);
    printarr();
    return 0;
}