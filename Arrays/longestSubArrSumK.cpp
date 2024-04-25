#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarray(vector<int> nums, int k){ // Optimal only when elements are positive.
    int left = 0; 
    int maxLen = 0;
    int sum = 0;

    for(int right = 0; right < nums.size(); right++){
        sum += nums[right];

        while(sum > k){
            sum -= nums[left];
            left++;
        }

        if(sum == k){
            maxLen = max(maxLen, right - left + 1);
        }
    }
    return maxLen;
}

int longestSubArraySum(vector<int> &nums, int k){ // optimal when elements are positive and(or) negative.
    unordered_map<int, int> mp;

    int prefixSum = 0;
    int maxLen = 0;

    for(int i = 0; i < nums.size(); i++){
        prefixSum += nums[i];

        if(prefixSum == k){
            maxLen = i+1;
        }

        if(mp.find(prefixSum - k)!= mp.end()){
            maxLen = max(maxLen, i - mp[prefixSum - k]);
        }

        if(mp.find(prefixSum) == mp.end()){
            mp[nums[i]] = i;
        }
    }
}

int main(){
    vector<int> arr = {1, 2, 0, 0, 0, 1, 0, 9, 7};
    int k = 3;
    cout<<longestSubarray(arr, k)<<"\n";
    return 0;
}