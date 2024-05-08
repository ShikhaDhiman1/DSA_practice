#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> quads(vector<int> &nums, int target){
    sort(nums.begin(), nums.end());
    set<vector<int>>st;

    int n = nums.size();

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int h = j + 1; h < n; h++){
                for(int k = h + 1; k < n; k++){
                    long long sum = nums[i] + nums[j] + nums[h] + nums[k];
                    if(sum == target){
                        vector<int> temp = {nums[i], nums[j], nums[h], nums[k]};
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> quads2(vector<int> &nums, int target){
    // unordered_map<int, int> mp;
    // OR use a set as hashset
    set<int> hashset;
    set<vector<int>> st;

    for(int i = 0; i < nums.size(); i++){
        for(int j = i + 1; j < nums.size(); j++){
            for(int k = j + 1; k < nums.size(); k++){
                int l = target - (nums[i] + nums[j] + nums[k]);
                // if(mp[l] == 0){
                //     mp[nums[k]]++;
                // }
                if(hashset.find(l) == hashset.end()){
                    hashset.insert(nums[k]);
                }
                else{
                    vector<int> temp = {nums[i], nums[j], l, nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}

vector<vector<int>> quads3(vector<int> &nums, int target){
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++){
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        for(int j = i + 1; j < nums.size(); j++){
            if(j > i + 1 && nums[j] == nums[j - 1]) continue;

            int k = nums.size() - 1;
            int l = j + 1;

            while(l < k){
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[l] + (long long)nums[k];
                if(sum < target){
                    l++;
                }
                else if(sum > target){
                    k--;
                }
                else{
                    vector<int> temp = {nums[i], nums[j], nums[l], nums[k]};
                    ans.push_back(temp);
                    l++;
                    k--;
                    while(l < k && nums[l] == nums[l - 1]) l++;
                    while(l < k && nums[k] == nums[k + 1]) k++;
                }
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {2, 2, 2, 2, 1, 3};
    int target = 8;

    arr = {-1, 0, 1, 1, -1, -1, 0};
    target = 0;

    vector<vector<int>> ans = quads(arr, target);

    for(auto vec : ans){
        for(auto x : vec){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";

    vector<vector<int>> ans2 = quads2(arr, target);

    for(auto vec : ans2){
        for(auto x : vec){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";

    vector<vector<int>> ans3 = quads3(arr, target);

    for(auto vec : ans3){
        for(auto x : vec){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";

    return 0;
}