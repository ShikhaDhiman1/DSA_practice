#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> majorityElements(vector<int> &nums){
    vector<int> ans;
    
    for(int i = 0; i < nums.size(); i++){
        if(ans.empty() || find(ans.begin(), ans.end(), nums[i]) == ans.end()){
            int count = 1;
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i] == nums[j]){
                    count++;
                }
            }
            if(count > nums.size()/3){
                ans.push_back(nums[i]);
            }
        }
    }
    return ans;
}

vector<int> majorityElements2(vector<int> &nums){
    map<int, int> mp;
    vector<int> ans;

    for(auto x : nums){
        mp[x]++;
        if(mp[x] == nums.size()/3 + 1){
            ans.push_back(x);
        }
    }
    sort(ans.begin(), ans.end()); // T.C.  = O(2log2) = 2 => as good as constant
    return ans;
}

vector<int> majorityElements3(vector<int> &nums){
    vector<int> ans;
    int cnt1 = 0, cnt2 = 0;
    int candidate1 = INT_MIN, candidate2 = INT_MIN;

    for(int i = 0; i < nums.size(); i++){
        if(cnt1 == 0 && nums[i] != candidate2){
            candidate1 = nums[i];
            cnt1 = 1;
        }
        else if(cnt2 == 0 && nums[i] != candidate1){
            candidate2 = nums[i];
            cnt2 = 1;
        }
        else if(nums[i] == candidate1) cnt1++;
        else if(nums[i] == candidate2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == candidate1) cnt1++;
        else if(nums[i] == candidate2) cnt2++;
    }
    int thresh = (int)nums.size()/3;
    if(cnt1 > thresh){
        ans.push_back(candidate1);
    }
    if(cnt2 > thresh){
        ans.push_back(candidate2);
    }
    sort(ans.begin(), ans.end());

    return ans;
}

int main(){
    vector<int> nums = {1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 1, 1, 2, 3};
    vector<int> ans = majorityElements(nums);
    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<"\n";

    vector<int> ans2 = majorityElements2(nums);
    for(auto x : ans2){
        cout<<x<<" ";
    }
    cout<<"\n";

    vector<int> ans3 = majorityElements3(nums);
    for(auto x : ans3){
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}