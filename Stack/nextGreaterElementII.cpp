#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterII(vector<int> &nums){
    int n = nums.size();
    stack<int> st;
    vector<int> vec(n, -1);

    for(int i = (2 * n) - 1; i >= 0; i--){
        while((!st.empty()) && st.top() <= nums[i % n]){
            st.pop();
        }
        if(!st.empty()) vec[i % n] = st.top();

        st.push(nums[i % n]);
    }

    vector<int> ans;
    for(int i = 0; i < n; i++){
        ans.push_back(vec[i]);
    }

    return ans;
}

int main(){
    vector<int> nums = {100,1,11,1,120,111,123,1,-1,-100};

    vector<int> ans = nextGreaterII(nums);
    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<"\n\n";
    return 0;
}