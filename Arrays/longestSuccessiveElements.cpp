#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int longestSuccessiveElements(vector<int> &nums){
    if(nums.empty()) return 0;
    sort(nums.begin(), nums.end());

    int len = 1;
    int maxLen = 1;
    for(int i = 0; i < nums.size() - 1; i++){
        if(nums[i] != nums[i+1]){
            if(nums[i + 1] - nums[i] == 1){
                len++;
                maxLen = max(maxLen, len);
            }
            else{
                len = 1;
            }
        }
    }
    return maxLen;
}

int longestSuccessiveElements2(vector<int> &nums){
    if(nums.empty()) return 0;

    unordered_set<int> st;

    for(int i = 0; i < nums.size(); i++){
        st.insert(nums[i]);
    }

    int maxLen = 1;
    for(auto x : st){
        int currNum = x;
        if(st.find(x - 1) == st.end()){
            int len = 1;
            while(st.find(currNum + 1) != st.end()){
                len++;
                currNum++;
            }
            maxLen = max(maxLen, len);
        }
    }
    return maxLen;
}

int main(){
    vector<int> arr = {15, 6, 2, 1, 16, 4, 2, 29, 9, 12, 8, 5, 14, 21, 8, 12, 17, 16, 6, 26, 3};
    arr = {1, 2, 2 ,1};
    cout<<longestSuccessiveElements(arr)<<"\n";

    cout<<longestSuccessiveElements2(arr)<<"\n";

    return 0;
}