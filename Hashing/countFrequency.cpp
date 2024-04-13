#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> countFrequency(int n, int x, vector<int> &nums){
    unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); i++){
        cout<<map[i]<<" ";
        map[nums[i]]++;
        cout<<map[i]<<"\n";
    }
    vector<int> ans;
    for(int i = 0; i < n; i++){
        ans[i] = map[i+1];
    }

    return ans;
}

int main(){
    vector<int> nums = {1,3,1,9,2,7};
    vector<int> ans = countFrequency(6,9,nums);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}