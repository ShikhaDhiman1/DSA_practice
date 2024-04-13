#include <iostream>
using namespace std;

void swapAlter(int *arr, int n){
    for(int i = 0; i < n-1; i+=2){
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
    return;
}

int main(){
    int n, arr[100];
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the array: ";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    swapAlter(arr, n);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}