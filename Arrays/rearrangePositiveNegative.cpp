#include <iostream>
#include <vector>
using namespace std;

void alternateNumbers(vector<int> &nums){
    vector<int> pos;
    vector<int> neg;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] >= 0){
            pos.push_back(nums[i]);
        }else{
            neg.push_back(nums[i]);
        }
    }

    for(int j = 0; j < nums.size()/2; j++){
        nums[2*j] = pos[j];
        nums[2*j + 1] = neg[j];
    }
}

vector<int> alternateNumbers2(vector<int> &nums){
    int posIndex = 0;
    int negIndex = 1;

    vector<int> ans(nums.size(), 0);

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] >= 0){
            ans[posIndex] = nums[i];
            posIndex += 2;
        }else{
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {-1, -2, 3, -6, 4, 5, 9, -10};
    vector<int> ans = alternateNumbers2(nums);
    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<"\n";

    alternateNumbers(nums);
    for(auto x : nums){
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}