#include <iostream>
using namespace std;

void printArr(int arr[], int n){

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}

int main(){
    int arr[10];
    cout<<"Elements of arr : ";
    // for(int i = 0; i < 10; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    printArr(arr, 10);

    int arr1[3] = {}; // stores zeroes
    cout<<"Elements of arr1 : ";
    // for(int i = 0; i < 3; i++){
    //     cout<<arr1[i]<<" ";
    // }
    // cout<<endl;
    printArr(arr1, 3);

    int arr2[5] = {1,2}; // stores zero in remaining indexes
    cout<<"Elements of arr2 : ";
    // for(int i = 0; i < 5; i++){
    //     cout<<arr2[i]<<" ";
    // }
    // cout<<endl;
    printArr(arr2, 5);

    int arr3[5] = {1}; // stores zeroes
    cout<<"Elements of arr3 : ";
    // for(int i = 0; i < 5; i++){
    //     cout<<arr3[i]<<" ";
    // }
    // cout<<endl;
    printArr(arr3, 5);

    return 0;
}