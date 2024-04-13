#include <iostream>
#include <vector>
using namespace std;

void reverse1(vector<int> &arr){
    for(int i = 0; i < arr.size()/2; i++){
        int temp = arr[i];
        arr[i] = arr[arr.size()-i-1];
        arr[arr.size()-i-1] = temp; 
    }
    return;
}

void reverse2(vector<int> &arr){
    int start = 0;
    int end = arr.size()-1;

    while(start <= end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main(){
    vector<int> arr;
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;

    cout<<"Enter the array : ";
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    cout<<"\nAfter reversing the array : ";
    reverse1(arr);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"\nAgain reversing the array : ";
    reverse2(arr);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;


    return 0;
}