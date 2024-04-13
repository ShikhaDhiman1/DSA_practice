#include <iostream>
using namespace std;

bool search(int *arr, int size, int key){
    for(int i = 0; i < size; i++){
        if(arr[i] == key) return true;
    }
    return false;
}

int main(){
    int n, arr[100], key;
    cout<<"Enter the size of Array: ";
    cin>>n;
    cout<<"Enter the array: ";
    for(int  i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the key to be found: ";
    cin>>key;
    cout<<endl;
    if(search(arr, n, key)) cout<<key<<" is found in the array.\n";
    else cout<<key<<" is not present in the array!\n";
    cout<<endl;
    return 0;
}