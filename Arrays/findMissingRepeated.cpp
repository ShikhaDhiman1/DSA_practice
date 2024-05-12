#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findTwoElements(vector<int> &arr){
    int n = arr.size();

    int sum = n*(n+1)/2;
    int cumulativeSum = 0;
    unordered_map<int, int> mp;
    vector<int> ans;

    for(auto x : arr){
        mp[x]++;
        if(mp[x] == 2){
            ans.push_back(mp[x]);
        }
        else{
            cumulativeSum += x;
        }
    }
    ans.push_back(sum - cumulativeSum);

    return ans;
}

vector<int> findTwoElements2(vector<int> &arr){
    vector<int> ans;
    unordered_map<int, int> mp;
    
    for(int i = 0; i < arr.size(); i++){
        mp[arr[i]]++;
        if(mp[arr[i]] == 2){
            ans.push_back(arr[i]);
        }
    }
    for(int i = 1; i <= arr.size(); i++){
        if(mp[i] == 0){
            ans.push_back(i);
            break;
        }
    }
    return ans;
}

vector<int> findMissingAndRepeatedEle(vector<vector<int>> &grid){
    unordered_map<int, int> mp;
        vector<int> ans;

        int n = grid.size()*grid.size();
        int sum = n*(n+1)/2;

        int cumulativeSum = 0;

        for(auto vec : grid){
            for(auto x : vec){
                mp[x]++;
                if(mp[x] == 2){
                    ans.push_back(x);
                }else{
                    cumulativeSum += x;
                }
            }
        }
        ans.push_back(sum - cumulativeSum);
        return ans;
}

int main(){
    vector<int> nums = {7, 1, 2, 5, 4, 4, 3};
    vector<int> ans1 = findTwoElements(nums);
    vector<int> ans2 = findTwoElements2(nums);

    for(auto x : ans1){
        cout<<x<<" ";
    }
    cout<<"\n";

    for(auto x : ans2){
        cout<<x<<" ";
    }
    cout<<"\n";

    vector<vector<int>> grid = {{9, 1, 2}, {3, 7, 8},{6, 9, 4}};
    vector<int> ans3 = findMissingAndRepeatedEle(grid);
    for(auto x : ans3){
        cout<<x<<" ";
    }
    cout<<"\n";

    return 0;
}