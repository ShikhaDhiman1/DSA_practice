#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

// BRUTE FORCE:->
int subarraysWithGivenSum(vector<int> &nums, int k){
    int sum = 0;
    int count = 0;

    for(int i = 0; i < nums.size(); i++){
        for(int j = i; j < nums.size(); j++){
            sum += nums[j];
            if(sum == k){
                cout<<i<<", "<<j<<"\n";
                count++;
            }            
        }
        sum = 0;
    }
    return count;
}

int findSubarraysWithGivenSum(vector<int> &nums, int k){ //T.C. = O(n*logn) , S.C. = O(n)
    int prefixSum = 0;
    int count = 0;

    unordered_map<int, int> mp; //{prefixSum, count} [----> count is important here]
    mp[0] = 1; // storing of 0 is very important
    for(int i = 0; i < nums.size(); i++){
        prefixSum += nums[i];
        mp[prefixSum]++;
        // if(mp[prefixSum - k] != 0){
        count += mp[prefixSum - k];
        // }
    }
    return count;
}


int main(){
    vector<int> arr = {3, 1, 2, 4};
    arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int k = 3;
    cout<<subarraysWithGivenSum(arr, k)<<"\n";
    cout<<findSubarraysWithGivenSum(arr, k)<<"\n";
    return 0;
}