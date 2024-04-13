#include <iostream>
using namespace std;

int sum(int *arr, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

int main(){
    int n;
    cout<<"\nEnter the size of array: ";
    cin>>n;
    int arr[100];
    cout<<"Enter the array : ";
    for(int i = 0; i < n ; i++){
        cin>>arr[i];
    }
    cout<<"\nSum of elements of the array is : "<<sum(arr, n);
    cout<<endl<<endl;
    return 0;
}