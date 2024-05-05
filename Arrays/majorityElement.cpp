#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int majorElement(vector<int> &nums){
    unordered_map<int, int> mp;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        mp[nums[i]]++;
        if(mp[nums[i]] > n/2) return nums[i];
    }
    return -1;
}

int majorElement2(vector<int> nums){
    sort(nums.begin(), nums.end());
    int n = nums.size();
    return nums[n/2];
}

// Moore's Voting algorithm
int majorElement3(vector<int> &nums){
    int count = 0;
    int candidate = nums[0];

    for(int i = 0; i < nums.size(); i++){
        if(count == 0){
            candidate = nums[i];
            count = 1;
        }
        else if(nums[i] == candidate){
            count++;
        }else{
            count--;
        }
    }

    return candidate;
}

int main(){
    vector<int> arr = {3, 2, 3, 9, 1, 3, 0, 3, 3};
    cout<<majorElement(arr)<<"\n";
    cout<<majorElement2(arr)<<"\n";
    cout<<majorElement3(arr)<<"\n";

    return 0;
}