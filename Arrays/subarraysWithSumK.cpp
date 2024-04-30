#include <iostream>
#include <vector>
using namespace std;

int findSubarraysWithGivenSum(vector<int> &nums, int k){
    int sum = 0;
    int count = 0;
    int left = 0;

    for(int right = 0; right < nums.size(); right++){
        sum += nums[right];

        while(sum > k){
            sum -= nums[left];
            left++;
        }
        if(sum == k){
            count++;
        }
    }
    return count;
}

int main(){
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    cout<<findSubarraysWithGivenSum(arr, k)<<"\n";
    return 0;
}