#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(vector<int> &arr){
    for(int i = 1; i < arr.size(); i++){
        for(int j = 0; j < arr.size() - i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(){
    vector<int> nums = {9, 3, 19, 0, 5, 12, 1, 0};

    bubbleSort(nums);

    cout<<"\n";
    for(auto x : nums){
        cout<<x<<" ";
    }
    cout<<"\n\n";
    return 0;
}