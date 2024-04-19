#include <iostream>
#include <vector>
using namespace std;

void selectSort(vector<int> &arr){

    for(int i = 0; i < arr.size()-1; i++){
        int minIndex = i;
        for(int j = i + 1; j < arr.size(); j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i) swap(arr[i], arr[minIndex]);
    }
    return;
}

int main(){
    vector<int> nums = {9, 3, 19, 0, 5, 12, 1, 0};
    
    selectSort(nums);

    for(auto x : nums){
        cout<<x<<" ";
    }
    cout<<"\n\n";
    return 0;
}