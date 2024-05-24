#include <iostream>
#include <vector>
using namespace std;

// Given a sorted array arr[] of size N without duplicates, and given a value x. 
// Floor of x is defined as the largest element K in arr[] such that K is smaller 
// than or equal to x. Find the index of K(0-based indexing).

int findFloor(vector<int> nums, int x)
{
    int left = 0;
    int right = nums.size() - 1;

    int ans = -1;

    while(left <= right){
        int mid = left + (right - left)/2;

        if(nums[mid] == x) return mid;
        else if(nums[mid] < x){
            ans = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int x = 0;
    x = 3;
    cout<<findFloor(nums, x)<<"\n";
    return 0;
}