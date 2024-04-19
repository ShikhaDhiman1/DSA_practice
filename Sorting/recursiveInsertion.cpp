#include <iostream>
using namespace std;

void insertionSort(int *arr, int i, int n){
    if(i == n) return;

    int j = i;
    while(j > 0 && arr[j-1] > arr[j]){
        swap(arr[j-1], arr[j]);
        j--;
    }
    insertionSort(arr, i+1, n);
}

int main(){
    int arr[] = {2, 13, 4, 1, 3, 6, 28, 1};

    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr,0, n);

    cout<<"\n";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n";

    return 0;
}