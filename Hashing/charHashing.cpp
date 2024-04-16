#include <iostream>
using namespace std;

int main(){
    // cout<<'a'-97<<endl;
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;

    cout<<"Enter the array : ";
    char arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int hash[26] = {0};

    for(int i = 0; i < n; i++){
        hash[arr[i] - 97]++; // or  hash[arr[i] - 'a']
    }

    int q;
    cout<<"Enter the number of elements to check frequency : ";
    cin>>q;

    while(q--){
        char ch;
        cin>>ch;

        cout<<"Frequency of "<<ch<<" is: "<<hash[ch-97]<<"\n"; // or hash[ch-'a']
    }
    return 0;
}