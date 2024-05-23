#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int target, int left, int right){
    if(left > right) return -1;

    int mid = left + (right - left)/2;

    if(nums[mid] == target) return mid;
    
    if(nums[mid] > target){
        return binarySearch(nums, target, left, mid - 1);
    }

    return binarySearch(nums, target, mid + 1, right);
}

int binarySearch2(vector<int> &nums, int target){
    int left = 0;
    int right = nums.size() - 1;

    while(left <= right){
        int mid = left + (right - left)/2;

        if(nums[mid] == target) return mid;
        else if(nums[mid] > target){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {-1, 0, 2, 4, 4, 4, 5, 8, 10, 14, 15, 16, 20, 22};
    int target = 4;
    cout<<binarySearch(nums, target, 0, nums.size() - 1)<<"\n";
    cout<<binarySearch2(nums, target)<<"\n";
    return 0;
}