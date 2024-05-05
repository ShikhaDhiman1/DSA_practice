#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> triplets(vector<int> &nums){
    vector<vector<int>> ans;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    vector<int>temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    if(find(ans.begin(), ans.end(), temp) == ans.end()){
                        ans.push_back(temp);
                    }
                }
            }
        }
    }
    return ans;
}

vector<vector<int>> triplets2(vector<int> &nums){
    unordered_map<int, int> mp;
    set<vector<int>> st;

    for(int i = 0; i < nums.size(); i++){
        for(int j = i + 1; j < nums.size(); j++){
            int k = -(nums[i] + nums[j]);
            if(mp.find(k) == mp.end()){
                mp[nums[j]]++;
            }else{
                vector<int> temp = {nums[i], nums[j], k};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
        }
        mp.clear();
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> triplets3(vector<int> &nums){
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++){
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1;
        int k = nums.size() - 1;

        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];

            if(sum < 0){
                j++;
            }
            else if(sum > 0){
                k--;
            }
            else{
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j < k && nums[j] == nums[j - 1]) j++;
                while(j < k && nums[k] == nums[k + 1]) k--;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = triplets(arr);
    for(auto vec : ans){
        for(auto x : vec){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";

    vector<vector<int>> ans2 = triplets2(arr);
    for(auto vec : ans2){
        for(auto x : vec){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";

    vector<vector<int>> ans3 = triplets3(arr);
    for(auto vec : ans3){
        for(auto x : vec){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";

    return 0;
}