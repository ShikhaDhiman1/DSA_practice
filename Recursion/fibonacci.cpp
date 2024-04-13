#include <iostream>
using namespace std;

int fibo(int n){
    if(n == 0 || n == 1){
        return n;
    }
    return fibo(n-2) + fibo(n-1);
}

int* fibonacci(int n){
    int* arr = new int[n]; // dynamically allocated array
    // static int arr[n]; // or using static array ==> but we can only give static storage to arr[] as a variable lenght array cannot have static storage duration
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2; i < n; i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
    return arr;
}

int main(){
    int n;
    cout<<"Enter the nuber till what you want the fibonacci series: ";
    cin>>n;

    // Fibonacci series using recursive method:
    cout<<fibo(n-1)<<endl;
    for(int i = 0; i < n; i++){
       cout<<fibo(i)<<" ";
    }
    cout<<endl;

    // Fibonacci series using array and iterative method:
    int* arr = fibonacci(n);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    delete[] arr; // deleting the dynamically allocated array after accessing in the main function.
    cout<<endl;

    return 0;
}