#include <iostream>
#include <vector>
using namespace std;

int findPeak(vector<int> &nums){
    // int n = nums.size();
    // if(n == 1) return 0;
    // if(nums[0] > nums[1]) return 0;
    // for(int i = 1; i < n - 1; i++){
    //     if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1]){
    //         return i;
    //     }
    // }
    // return -1;

    int n = nums.size();
    if(n == 1) return 0;
    for(int i = 0; i < n - 1; i++){
        if(nums[i] > nums[i + 1]) return i;
    }
    return n - 1;
}

int findPeak2(vector<int> &nums){
    int n = nums.size();
    if(n == 1) return 0;
    if(nums[0] > nums[1]) return 0;
    if(nums[n - 1] > nums[n - 2]) return n-1;

    int left = 1, right = n - 2;

    while(left <= right){
        int mid = (left + right)/2;

        if(nums[mid -1] < nums[mid] && nums[mid] > nums[mid + 1]) return mid;
        // else if(nums[mid - 1] < nums[mid]){
        //     left = mid + 1;
        // }
        else if(nums[mid] > nums[mid + 1]){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {1, 3, 4, 1, 3, 5, 6, 8, 4, 3};
    cout<<findPeak(nums)<<"\n";
    cout<<findPeak2(nums)<<"\n";
    return 0;
}