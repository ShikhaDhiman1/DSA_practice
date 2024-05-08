#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarrayWithSumZero(vector<int> &nums){
    int maxLen = 0;
    unordered_map<int, int> mp;
    int sum = 0;

    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];

        if(sum == 0){
            maxLen = i + 1;
        }
        else if(mp.find(sum) != mp.end()){
            maxLen = max(maxLen, i - mp[sum]);
        }
        else{
            mp[sum] = i;
        }
    }
    return maxLen;
}
int main(){
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    cout<<longestSubarrayWithSumZero(arr)<<"\n";
    return 0;
}