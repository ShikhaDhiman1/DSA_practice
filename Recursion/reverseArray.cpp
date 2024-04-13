#include <iostream>
using namespace std;

void reverse(int i, int j, int * arr){
    if( i >= j) return;

    swap(arr[i], arr[j]);

    reverse(i+1, j-1, arr);
}

void reverse2(int i, int n, int* arr){
    if(i >= n/2) return;

    swap(arr[i], arr[n-i-1]);

    reverse2(i+1, n, arr);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};

    reverse(0, 4, arr);

    cout<<"\n";
    for(int i = 0; i < 5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n";

    reverse2(0, 5, arr);

    for(int i = 0; i < 5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n";
    
    return 0;
}