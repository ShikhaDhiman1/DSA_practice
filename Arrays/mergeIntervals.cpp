#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());

    for(int i = 0; i < intervals.size(); i++){
        int start = intervals[i][0];
        int end = intervals[i][1];

        if(!ans.empty() && end <= ans.back()[1]) continue;

        for(int j = i + 1; j < intervals.size(); j++){
            if(intervals[j][0] <= end){
                end = max(end, intervals[j][1]);
            }
            else{
                break;
            }
        }
        vector<int> temp = {start, end};
        ans.push_back(temp);
    }
    return ans;
}

vector<vector<int>> mergeInterval(vector<vector<int>> &intervals){
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());

    ans.push_back(intervals[0]);

    for(int i = 1; i < intervals.size(); i++){
        if(intervals[i][0] <= ans.back()[1]){
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        else{
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> nums = {{1, 3}, {2, 4}, {2, 6}, {8, 9}, {8, 10}, {9, 11}, {15, 18}, {16, 17}};
    vector<vector<int>> ans1 = mergeIntervals(nums);
    for(auto interval : ans1){
        cout<<"{";
        for(auto x : interval){
            cout<<x<<" ";
        }
        cout<<"}, ";
    }
    cout<<"\n";

    vector<vector<int>> ans2 = mergeInterval(nums);
    for(auto interval : ans2){
        cout<<"{";
        for(auto x : interval){
            cout<<x<<" ";
        }
        cout<<"}, ";
    }
    cout<<"\n";
    return 0;
}