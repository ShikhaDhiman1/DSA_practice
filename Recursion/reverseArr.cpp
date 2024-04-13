#include <iostream>
using namespace std;

int* reverse(int n, int* arr){ // using for loop
    int* ans = new int[n];

    for(int i = 0; i < n; i++){
        ans[i] = arr[n-i-1];
    }

    return ans;
}

void reverseIter(int n, int* arr){  // using while loop
    int start = 0;
    int end = n-1;

    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    } 
    return;
}

void reverseRecur(int start, int end, int* arr){ 
    if(start >= end) return;

    swap(arr[start], arr[end]);
    reverseRecur(start+1, end-1, arr);
    
    return;
}

int main(){
    int arr[100];
    int n;
    cout<<"Enter the size of array(less than n): ";
    cin>>n;

    cout<<"Enter the elements of array: ";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    cout<<"Reverse using an extra array:\n";
    int* ans = reverse(n, arr);
    for(int i = 0; i < n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    cout<<"Reverse using Iteration:\n";
    reverseIter(n, arr);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Reverse using recursion:\n";
    reverseRecur(0, n-1, arr);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}