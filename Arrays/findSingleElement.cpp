#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findSingleEle(vector<int> &nums){ // when input array is sorted
    for(int i = 0; i < nums.size()-1; i += 2){
        if(nums[i] != nums[i+1]){
            return nums[i];
        }
    }
    return -1;
}

int findSingleEle2(vector<int> &nums){ // when input array is unsorted
    unordered_map<int, int> mp;

    for(int i = 0; i < nums.size(); i++){
        mp[nums[i]]++;
    }

    for(auto it : mp){
        if(it.second == 1) return it.first;
    }

    return -1;
}

int findSingleEle3(vector<int> &nums){ // not working??
    int ans = 0;

    for(auto x : nums){
        ans ^= x;
    }
    return ans;
}

int main(){
    vector<int> arr = {1, 1, 2, 2, 3, 4, 4};
    cout<<findSingleEle(arr)<<"\n";

    vector<int> arr2 = {4, 1, 9, 2, 1, 3, 3, 8, 9, 4};
    cout<<findSingleEle2(arr2)<<"\n";

    vector<int> arr3 = {4, 1, 2, 1, 2};
    cout<<findSingleEle3(arr3)<<"\n";
    return 0;
}