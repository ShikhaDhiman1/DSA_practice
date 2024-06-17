#include <iostream>
#include <vector>
using namespace std;

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