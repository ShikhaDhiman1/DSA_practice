#include <iostream>
using namespace std;

void bubbleSort(int *arr, int n){
    if(n == 1) return;

    for(int j = 0; j < n-1; j++){
        if(arr[j] > arr[j+1]){
            swap(arr[j], arr[j+1]);
        }
    }

    bubbleSort(arr, n-1);
}

int main(){
    int arr[] = {2, 13, 4, 1, 3, 6, 28, 1};

    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, n);

    cout<<"\n";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n";

    return 0;
}