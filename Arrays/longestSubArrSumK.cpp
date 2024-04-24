#include<iostream>
#include <vector>
using namespace std;

int longestSubarray(vector<int> nums, int k){
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

int main(){
    vector<int> arr = {1, 2, 0, 0, 0, 1, 0, 9, 7};
    int k = 3;
    cout<<longestSubarray(arr, k)<<"\n";
    return 0;
}