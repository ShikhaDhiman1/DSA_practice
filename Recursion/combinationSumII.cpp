#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.*/

void getSubsets(int i, vector<int> candidates, int target, set<vector<int>> &ds, vector<int> vec){
    if(i == candidates.size()){
        if(target == 0){
            ds.insert(vec);
        }
        return;
    }

    if(candidates[i] <= target){
        vec.push_back(candidates[i]);
        getSubsets(i + 1, candidates, target - candidates[i], ds, vec);
        vec.pop_back();
    }
    getSubsets(i + 1, candidates, target, ds, vec);
}

vector<vector<int>> combinationSumII(vector<int> candidates, int target){
    sort(candidates.begin(), candidates.end());
    set<vector<int>> ds;
    getSubsets(0, candidates, target, ds, {});
    vector<vector<int>> ans;
    ans.insert(ans.begin(), ds.begin(), ds.end());

    return ans;
}

void getSubsets2(int index, vector<int> candidates, int target, vector<vector<int>> &ds, vector<int> vec){
    if(target == 0){
        ds.push_back(vec);
        return;
    }

    for(int i = index; i < candidates.size(); i++){
        if(i > index && (candidates[i] == candidates[i - 1])) continue;
        if(candidates[i] > target) break;

        vec.push_back(candidates[i]);
        getSubsets2(i + 1, candidates, target - candidates[i], ds, vec);
        vec.pop_back();
    }
}
vector<vector<int>> combinationSumIIOptimal(vector<int> candidates, int target){
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ds;
    getSubsets2(0, candidates, target, ds, {});
    return ds;
}
int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> ans = combinationSumII(candidates, target);

    for(auto vec: ans){
        cout<<"[";
        for(auto x : vec){
            cout<<x<<" ";
        }
        cout<<"], ";
    }
    cout<<endl;

    vector<vector<int>> ans2 = combinationSumIIOptimal(candidates, target);

    for(auto vec: ans2){
        cout<<"[";
        for(auto x : vec){
            cout<<x<<" ";
        }
        cout<<"], ";
    }
    cout<<endl;
    return 0;
}