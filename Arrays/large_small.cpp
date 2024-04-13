#include <iostream>
#include <climits>
using namespace std;

int largest(int *arr, int n){ // here we are not copying array from the original array but we are sending the address of the array. Therefore, updating an array in the function will update it in the original array.
    int maxi = INT_MIN;
    // arr[0] = maxi;
    for (int i = 0; i < n; i++){
        // if(arr[i] > max){
        //     maxi = arr[i];
        // }
        // OR
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

int small(int *arr, int n){
    // int n = sizeof(arr)/ sizeof(arr[0]); // only recommended if the array is full!
    int mini = INT_MAX;
    
    for (int i = 0; i < n; i++)
    {
        if(arr[i] < mini) mini = arr[i];
        // OR
        //mini = min(mini, arr[i])
    }
    cout<<endl;
    return mini;
}

int main(){
    int n;
    cout<<"\nEnter the number of values from which you want to get the largest number: ";
    cin>>n;
    int arr[100];
    cout<<"Enter the values: \n";
    for( int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<"\nThe largest value is : "<<largest(arr, n);
    cout<<endl;
    cout<<"\nThe smallest value is : "<<small(arr, n);
    cout<<endl<<endl;
    return 0;
}