#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int> &nums){
    int n = nums.size();
    int brkPoint = -1;

    for(int i = n-2; i >= 0; i--){
        if(nums[i] < nums[i+1]){
            brkPoint = i;
            break;
        }
    }
    if(brkPoint == -1){
        reverse(nums.begin(), nums.end());
        return;
    }

    for(int i = n - 1; i >= 0; i--){
        if(nums[i] > nums[brkPoint]){
            swap(nums[i], nums[brkPoint]);
            break;
        }
    }

    reverse(nums.begin() + brkPoint + 1, nums.end());
    return;
}

int main(){
    vector<int> arr = {2, 1, 5, 4, 3, 0, 1, 9};
    nextPermutation(arr);
    cout<<"Next permutation of array 'arr' : ";
    for(auto x : arr){
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}
