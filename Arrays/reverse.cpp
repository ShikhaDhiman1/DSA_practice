#include <iostream>
using namespace std;

void printArray(int *arr, int n){
    cout<<endl;
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}

void update(int *n){
    (*n)++;
    return;
}

int& update2(int a){
    int &ans = a;
    ans++;
    return ans;
}

void reverse(int *arr, int size){
    for(int i = 0; i <= size/2; i++){
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    return;
}

void reverse2(int *arr, int size){
    int start = 0;
    int end = size - 1;
    while( !(start > end)){  // or while(start <= end)
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
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
    reverse(arr, n);
    // for(int i = 0; i < n; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    printArray(arr, n);
    reverse2(arr, n);
    // for(int i = 0; i < n; i++){
    //     cout<<arr[i]<<" ";
    // }
    printArray(arr, n);

    int num = 10;
    cout<<update2(num)<<endl;
    cout<<endl;
    return 0;
}