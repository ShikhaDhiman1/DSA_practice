#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProdSubarray(vector<int> &nums){
    int maxProd = INT_MIN;
    int prod = 1;

    for(int i = 0; i < nums.size(); i++){
        for(int j = i; j < nums.size(); j++){
            prod *= nums[j];
            maxProd = max(maxProd, prod);
        }
        prod = 1;
    }

    return maxProd;
}

int maxProdSubbaray2(vector<int> &nums){
    int maxProd = INT_MIN;
    int suffix = 1;
    int prefix = 1;

    int n = nums.size();

    for(int i = 0; i < n; i++){
        if(suffix == 0) suffix = 1;
        if(prefix == 0) prefix = 1;

        prefix *= nums[i];
        suffix *= nums[n - i - 1];

        maxProd = max(maxProd, max(prefix, suffix));
    }

    return maxProd;
}

int main(){
    vector<int> nums = {1, 3, 2, -1, 4, -6, 3, -2, 6};
    cout<<maxProdSubarray(nums)<<"\n";
    cout<<maxProdSubbaray2(nums)<<"\n";
    return 0;
}