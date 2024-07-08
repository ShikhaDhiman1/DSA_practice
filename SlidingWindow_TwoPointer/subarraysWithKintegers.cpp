#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.*/

int subarraysWithKDistinct(vector<int> &nums, int k){
    int ans = 0;
    for(int i = 0; i < nums.size(); i++){
        unordered_map<int, int> mp;
        for(int j = i; j < nums.size(); j++){
            mp[nums[j]]++;
            if(mp.size() == k) ans++;
            else if(mp.size() > k) break;
        }
    }
    return ans;
}

int subarraysSmallerEqualToKDistinct(vector<int> & nums, int k){
    int ans = 0;
    int l = 0, r = 0;
    unordered_map<int, int> mp;

    while(r < nums.size()){
        mp[nums[r]]++;
        while(mp.size() > k){
            mp[nums[l]]--;
            if(mp[nums[l]] == 0) mp.erase(nums[l]);
            l++;
        }
        if(mp.size() <= k) ans += (r - l + 1);
        r++;
    }

    return ans;
}
int subarraysWithKDistinct2(vector<int> &nums, int k)
{
    return subarraysSmallerEqualToKDistinct(nums, k) - subarraysSmallerEqualToKDistinct(nums, k - 1);
}

int main()
{
    vector<int> nums = {1,2,1,2,2,3};
    int k = 2;
    cout<<subarraysWithKDistinct(nums, k)<<"\n";
    cout<<subarraysWithKDistinct2(nums, k)<<"\n";
    return 0;
}