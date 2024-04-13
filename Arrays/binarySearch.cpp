#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// Binary Search using RECURSION:
bool binarySearch(int* arr, int start, int end, int key){
    if(start > end) return false;
    int mid = (start + end)/2;
    int k = arr[mid];
    if(k == key) return true;
    else if(key > k){
        binarySearch(arr, mid+1, end, key);
    }
    else{
        binarySearch(arr, start, mid-1, key);
    }
}

// Binary search using ITERATION:
int binarySearch2(int *arr, int n, int key){
    int start = 0;
    int end = n-1;

    while(start <= end){
        // int mid = (start + end)/2;
        int mid = start + (end - start)/2; // in case start and end = 2^31-1 (= INT_MAX)
        if( key == arr[mid]) return mid;
        // Go to left side of mid element
        else if(key < arr[mid]){
            end = mid - 1;
        }
        // Go to right side of mid element
        else{
            start = mid + 1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter the number of values in the array: ";
    cin>>n;
    int* arr = new int[n];
    cout<<"Enter the array: ";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);  // using STL
    cout<<"Sorted array is : ";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    if(binarySearch(arr, 0, n-1, 10)) cout<<"\nFound!!\n";
    else cout<<"\nNot Found!\n";

    cout<<endl;
    cout<<"Index of given key is: ";
    cout<<binarySearch2(arr, n, 10)<<endl;
    delete[] arr;
    return 0;
}