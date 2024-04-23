#include <iostream>
#include <vector>
using namespace std;

int getSingleEle(vector<int> &arr){
    int ans = 0;

    for(int i = 0; i < arr.size(); i+= 2){
        if(i+1 > arr.size()-1 || arr[i] != arr[i+1]){
            ans = arr[i];
            break;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1, 1, 2, 2, 5, 5, 7, 9, 9};
    cout<<getSingleEle(arr)<<"\n";
    return 0;
}