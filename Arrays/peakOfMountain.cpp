#include <iostream>
using namespace std;

int peak(int* arr, int n){
    int start = 0;
    int end = n-1;

    while(start < end){
        int mid = start + (end - start)/2;
        if(arr[mid] < arr[mid + 1]){
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }
    return start;
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int* arr = new int[n];
    cout<<"Enter the mountain array: ";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<"Peak index of the mountain array is : "<<peak(arr, n)<<endl;
    return 0;
}