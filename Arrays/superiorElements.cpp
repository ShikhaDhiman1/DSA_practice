#include <iostream>
#include <vector>
using namespace std;

vector<int> getSuperiorElements(vector<int> &nums){  // An element is called a Superior Element if it is greater than all the elements present to its right.
    int n = nums.size();
    vector<int> ans;

    int x = nums[n-1];
    ans.push_back(x);

    for(int i = n-2; i >= 0; i--){
        if(nums[i] > x){
            x = nums[i];
            ans.push_back(x);
        }
    }

    return ans;
}

int main(){
    vector<int> nums = {2, 1, 7, 1, 2, 5, 3, 0};
    vector<int> ans = getSuperiorElements(nums);
    
    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<"\n";

    return 0;
}