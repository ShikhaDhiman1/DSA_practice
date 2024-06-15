#include <iostream>
#include <vector>
#include <string>
using namespace std;

void genSubsets(int i, vector<int> &nums, vector<int> sub, vector<vector<int>> &ans){
    if(i >= nums.size()){
        ans.push_back(sub);
        return;
    }

    sub.push_back(nums[i]);
    genSubsets(i + 1, nums, sub, ans);
    sub.pop_back();
    genSubsets(i + 1, nums, sub, ans);
}

vector<vector<int>> subsets(vector<int> &nums){
    vector<vector<int>> ans;
    genSubsets(0, nums, {}, ans);
    return ans;
}

void getSubsets(int i, string s, string str, vector<string> &ans){
    if(i >= s.length()){
        ans.push_back(str);
        return;
    }

    str += s[i];
    getSubsets(i + 1, s, str, ans);
    str.pop_back();
    getSubsets(i + 1, s, str, ans);
}

int main(){
    vector<int> arr = {3, 1, 2};
    vector<vector<int>> ans = subsets(arr);
    cout<<"{";
    for(auto vec : ans){
        cout<<"[";
        for(auto x : vec){
            cout<<x<<"";
        }
        cout<<"], ";
    }
    cout<<"}\n";

    string s = "abc";
    vector<string> subset;
    getSubsets(0, s, "", subset);
    cout<<"[";
    for(auto str : subset){
        cout<<str<<", ";
    }
    cout<<"]";
    return 0;
}