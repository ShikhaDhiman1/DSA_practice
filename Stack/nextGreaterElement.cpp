#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;

vector<int> nextGreater(vector<int> &nums1, vector<int> &nums2){
    vector<int> ans;
    for(auto x : nums1){
        int pos = find(nums2.begin(), nums2.end(), x) - nums2.begin();
        while(pos + 1 < nums2.size() && nums2[pos + 1] < x){
            pos++;
        }
        if(pos + 1 < nums2.size()) ans.push_back(nums2[pos + 1]);
        else ans.push_back(-1);
    }

    return ans;
}

vector<int> nextGreater2(vector<int> &nums1, vector<int> &nums2){
    int n = nums2.size();
    stack<int> st;
    map<int, int> mp;

    mp[nums2[n - 1]] = -1;
    st.push(nums2[n - 1]);

    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && st.top() < nums2[i]){
            st.pop();
        }
        if(st.empty()) mp[nums2[i]] = -1;
        else mp[nums2[i]] = st.top();
        st.push(nums2[i]);
    }

    vector<int> ans;
    for(auto x : nums1){
        ans.push_back(mp[x]);
    }

    return ans;
}

int main(){
    vector<int> nums1 = {3, 5, 1};
    vector<int> nums2 = {6, 1,5, 2, 3, 0, 4, 9, 10};

    vector<int> ans1 = nextGreater(nums1, nums2);
    for(auto x : ans1){
        cout<<x<<" ";
    }
    cout<<"\n\n";

    vector<int> ans2 = nextGreater2(nums1, nums2);
    for(auto x : ans2){
        cout<<x<<" ";
    }
    cout<<"\n\n";
    return 0;
}