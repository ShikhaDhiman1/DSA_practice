#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    // unordered_map<int, int> mp;
    map<int, int> mp;

    int n;
    cout<<"Enter the size of array : ";
    cin>>n;

    vector<int> arr;
    cout<<"\nEnter the array: ";

    // int num;
    // do {
    //     cin>>num;
    //     arr.push_back(num);
    // }while(num != -1);

    // arr.pop_back();

    for(int i = 0; i < n; i++){
        int n;
        cin>>n;
        arr.push_back(n);
    }

    for(int i = 0; i < arr.size(); i++){
        mp[arr[i]]++;
    }

    // OR -->
    // can be done in one single loop but it won't effect the time complexity since O(n+n) == O(n);
    // for(int i = 0; i < n; i++){
    //     cin>>arr[i];
    //     mp[arr[i]]++;
    // }
    cout<<"Frequency of elements in the array : \n";

    for(auto it : mp){
        cout<<it.first<<" --> "<<it.second<<"\n";
    }
    cout<<"\n";

    return 0;
}