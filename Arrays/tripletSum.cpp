#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tripletSum(vector<int> &nums, int key){
    vector <vector<int>> ans;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                if((nums[i] + nums[j] + nums[k]) == key){
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    ans.push_back(v);
                }
            }
        }
    }
    return ans;
}

int main(){
    vector <int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(6);

    vector <vector<int>> ans = tripletSum(nums, 12);

    for(int i = 0; i < ans.size(); i++){
        cout<<"[ ";
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    cout<<endl;

    return 0;
}