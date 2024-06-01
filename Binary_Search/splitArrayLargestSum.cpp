#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int subarraysWithSum(vector<int> &nums, int maxSum){
    int subarrays = 1;
    int subarraySum = 0;

    for(int i = 0; i < nums.size(); i++){
        if(subarraySum + nums[i] <= maxSum){
            subarraySum += nums[i];
        }
        else{
            subarrays++;
            subarraySum = nums[i];
        }
    }

    return subarrays;
}

int splitArrayMaxSum(vector<int> &nums, int k){
    int n = nums.size();
    if(k > n) return -1;
    int low = *max_element(nums.begin(), nums.end());
    if(k == n) return low;

    int high = accumulate(nums.begin(), nums.end(), 0);
    if(k == 1) return high;

    // BRUTE
    // for(int sum = low; sum <= high; sum++){
    //     if(subarraysWithSum(nums, sum) == k){
    //         return sum;
    //     }
    // }
    // return low;

    // OPTIMAL using BINARY
    while(low <= high){
        int mid = (low + high)/2;

        if(subarraysWithSum(nums, mid) <= k){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> nums = {2, 3, 1, 1, 1, 1, 1};
    int k = 5;
    cout<<splitArrayMaxSum(nums, k)<<"\n";
    return 0;
}