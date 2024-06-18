#include <iostream>
#include <vector>
using namespace std;

void getSubsetSum(int i, vector<int> &nums, vector<int> &ds, int sum){
    if(i == nums.size()){
        ds.push_back(sum);
        return;
    }

    sum += nums[i];
    getSubsetSum(i + 1, nums, ds, sum);
    sum -= nums[i];
    getSubsetSum(i + 1, nums, ds, sum);
}
vector<int> subsetSums(vector<int> nums){
    vector<int> ds;
    getSubsetSum(0, nums, ds, 0);
    return ds;
}

int main(){
    vector<int> nums = {0, 2, 4, 5};
    vector <int> ans = subsetSums(nums);

    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}