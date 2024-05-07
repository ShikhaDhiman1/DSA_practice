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
                    int sum = nums[i] + nums[j] + nums[h] + nums[k];
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
    unordered_map<int, int> mp;
    set<vector<int>> st;

    for(int i = 0; i < nums.size(); i++){
        for(int j = i + 1; j < nums.size(); j++){
            for(int k = j + 1; k < nums.size(); k++){
                int l = target - (nums[i] + nums[j] + nums[k]);
                if(mp[l] == 0){
                    mp[nums[k]]++;
                }
                else{
                    vector<int> temp = {nums[i], nums[j], nums[l], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}

int main(){
    vector<int> arr = {2, 2, 2, 2, 1, 3};
    arr = {-1, 0, 1, 1, -1, -1, 0};
    int target = 8;
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

    return 0;
}