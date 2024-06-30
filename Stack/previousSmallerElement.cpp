#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.
More formally,
    G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.*/

vector<int> prevSmaller(vector<int> &nums){
    int n = nums.size();
    stack<int> st;
    vector<int> vec(n, -1);

    for(int i= 0; i < n; i++){
        while(!st.empty() && st.top() >= nums[i]){
            st.pop();
        }
        if(!st.empty()) vec[i] = st.top();

        st.push(nums[i]);
    }

    return vec;
}

int main(){
    vector<int> nums = {39, 27, 11, 4, 24, 32, 32, 1};
   
    vector<int> ans = prevSmaller(nums);
    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<"\n\n";
    return 0;
}