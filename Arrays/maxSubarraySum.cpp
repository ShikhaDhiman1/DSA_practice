#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySum(vector<int> &nums){
    // Brute Force :---------------------------->>>>>>>>>>>
    // int maxSum = nums[0];
    // for(int i = 0; i < nums.size(); i++){
    //     int sum = 0;
    //     for(int j = i; j < nums.size(); j++){
    //         sum += nums[j];
    //         maxSum = max(maxSum, sum);
    //     }
    // }
    // return maxSum;

    // Optimal Approach:------------------>>>>>>>>
    // KADANE's algorithm
    int sum = 0;
    int maxSum = nums[0];

    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        maxSum = max(maxSum, sum);
        if(sum < 0) sum = 0;
    }
    return maxSum;

    // To get the index of the subarray:------->>>>
    // int sum = 0;
    // int maxSum = nums[0];
    // int start = 0;
    // int end = 0;
    // for(int i = 0; i < nums.size(); i++){
    //     sum += nums[i];
    //     if(sum > maxSum || sum == maxSum){
    //         maxSum = sum;
    //         end = i;
    //     }
    //     if(sum < 0){
    //         sum = 0;
    //         start = i+1;
    //     }
    // }
    // cout<<start<<", "<<end<<"\n";
    // return maxSum;
}

int main(){
    vector<int> arr = {-1, -2, 3, 10, -4, 6, -2, 8, 0};
    cout<<maxSubarraySum(arr)<<"\n";
    return 0;
}