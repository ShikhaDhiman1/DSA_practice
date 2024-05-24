#include <iostream>
#include <vector>
using namespace std;

// Given a sorted array of distinct integers and a target value, return the index if 
// the target is found. If not, return the index where it would be if it were inserted in order.
// You must write an algorithm with O(log n) runtime complexity.

int searchInsert(vector<int> &nums, int target){
    int left = 0, right = nums.size() -1;
    int index = nums.size();

    while(left <= right){
        int mid = (left + right)/2;

        if(nums[mid] == target) return mid;
        else if(nums[mid] > target){
            index = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
}

int main(){
    vector<int> nums = {1, 3, 5, 6};
    int target = 7;
    cout<<searchInsert(nums, target)<<"\n";
    return 0;
}