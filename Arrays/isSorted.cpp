#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int>&arr){
    int count = 0;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > arr[(i+1) % arr.size()]){
            count++;
        }
        if(count > 1) return false;
    }
    return true;
}

int main(){
    vector<int> nums = {3, 4, 5, 1, 2};
    // vector<int> nums = {3, 4, 5, 1, 2, 4};
    cout<<isSorted(nums);
    return 0;
}