#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    set<vector<int>> s;
    for(int i = 0; i < nums.size(); i++){
        for(int j = i+1; j < nums.size(); j++){
            for(int k = j+1; k < nums.size(); k++){
                if((nums[i] + nums[j] + nums[k]) == 0){
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    // cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                    sort(v.begin(), v.end());
                    s.insert(v);
                }
            }
        }
        // int i = 0;
            // int j = i+1;
            // while(i < ans.size() && j < ans.size()){

            // }
    }
    for(auto i:s ){
            for(int j = 0; j < i.size(); j++){
                cout<<i[j]<<" ";
            }
            cout<<endl;
        }
    cout<<"121****************************\n";

        for( auto i : s){
            ans.push_back(i);
            
        }
    
    // for(int i = 0; i < ans.size(); i++){
    //         sort(ans[i].begin(), ans[i].end());
    //         for(int j = i+1; j < ans.size(); j++){
    //             sort(ans[j].begin(), ans[j].end());
    //             if(ans[i] == ans[j]){
    //                 ans[j].clear();
    //                 // ans.erase(ans[j], ans[j] + ans[j].size()-1) ;
    //                 ans.erase(ans.begin()+j);

    //             }
    //         }
    //     }
    return ans;
}

int main(){
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(-1);
    nums.push_back(-4);
    vector<vector<int>> ans = threeSum(nums);
    for(auto i: ans){
        for(int j = 0; j < i.size(); j++){
            cout<<i[j]<<" ";
        }
        cout<<endl;
    }

    vector<int> v1;
    v1.push_back(-1);
    v1.push_back(0);
    v1.push_back(1);

    vector<int> v2;
    v2.push_back(-1);
    v2.push_back(0);
    v2.push_back(1);
    cout<<(v1 == v2)<<endl;
    // cout<<"****************************\n";
    // vector<int> v3{4,-2,-9,9,7,9,10,-15,4,-9,-9,8,-6,7,-7,-2,4,-9,-7,-11,13,9,5,-8,10,8,-6,-1,-2,-6,6,-12,7,4,4,-9,-1,-1,-8,10,5,-10,-5,7,12,4,12,-6,10,-10,-2,8,7,10,7,2,-5,9,-14,9,-12,-1,4,2,11,-15,9,-13,-1,-14,4,12,-9,-15,-4,10,4,-7,-11,-9,-1,-6,14,-9,-10,-1,0,-8,-7,-6,8,-12,0,-3,5,-4,-11,-1,-10,4,-8,10,-7,-10,2,4,-14};
    // vector<vector<int>> ans1 = threeSum(v3);
    // for(auto i: ans1){
    //     for(int j = 0; j < i.size(); j++){
    //         cout<<i[j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<"*********************************\n";
    vector<int> v4{0,0,0,0};
    vector<vector<int>> ans2 = threeSum(v4);
    for(auto i: ans2){
        for(int j = 0; j < i.size(); j++){
            cout<<i[j]<<" ";
        }
        cout<<endl;
    }
    cout<<"*********************************\n";

    v2 = v4;
    for(int j = 0; j < v2.size(); j++){
            cout<<v2[j]<<" ";
        }
    return 0;
}