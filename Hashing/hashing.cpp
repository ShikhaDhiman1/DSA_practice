#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter elements of array: ";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int hash[13] = {0}; // for computing frequency of upto 12
    for(int i = 0; i < n; i++){
        hash[arr[i]]++;
    }

    int q;
    cout<<"Enter the number of elements to check frequency: ";
    cin>>q;
    while(q--){
        int num;
        cin>>num;

        cout<<"Frequency of "<<num<<" is: "<<hash[num]<<"\n";
    }

    return 0;
}