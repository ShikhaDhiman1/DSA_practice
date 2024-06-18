#include <iostream>
#include <vector>
using namespace std;

/*Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.*/

void getSubsetsWithSum(int i, vector<int> &a, int target, vector<vector<int>> &ds, vector<int> vec){
    if(i == a.size()){
        if(target == 0){
            ds.push_back(vec);
        }
        return;
    }

    if(a[i] <= target){
        vec.push_back(a[i]);
        getSubsetsWithSum(i, a, target - a[i], ds, vec);
        vec.pop_back();
    }
    getSubsetsWithSum(i + 1, a, target, ds, vec);
}


vector<vector<int>> combinationSum(vector<int> &a, int target){
    vector<vector<int>> ds;
    getSubsetsWithSum(0, a, target, ds, {});
    return ds;
}

int main(){
    vector<int> a = {2, 3, 4, 6, 7, 0, 1, 9};
    vector<vector<int>> ds = combinationSum(a, 7);

    for(auto vec : ds){
        cout<<"[";
        for(auto x : vec){
            cout<<x<<" ";
        }
        cout<<"],";
    }
    cout<<"\n";
    return 0;
}