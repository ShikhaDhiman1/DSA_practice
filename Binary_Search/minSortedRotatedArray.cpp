#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMin(vector<int> &nums){
    // int pivot = -1;
    // int n = nums.size();

    // if(nums[0] < nums[n - 1]) return nums[0];

    // for(int i = 0; i < n - 1; i++){
    //     if(nums[i] > nums[i + 1]){
    //         pivot = i;
    //         break;
    //     }
    // }
    // return nums[pivot + 1];

    int pivot = -1;
    for(int i = 0; i < nums.size() - 1; i++){
        if(nums[i] > nums[i + 1]){
            pivot = i;
            break;
        }
    }
    if(pivot == -1) return nums[0];
    return nums[pivot + 1];
}

int findMinBinarySearch(vector<int> &nums){
    int low = 0, high = nums.size() - 1;

    int minEle = INT_MAX;

    while(low <= high){
        int mid = (low + high)/2;

        if(nums[low] < nums[high]) return min(minEle, nums[low]);

        // if(nums[low] == nums[mid] && nums[mid] == nums[high]){
        //     low++;
        //     high--;
        //     continue;
        // }
        // if left part is sorted
        if(nums[low] <= nums[mid]){
            minEle = min(minEle, nums[low]);
            low = mid + 1;
        }
        // if right part is sorted
        else if(nums[high] >= nums[mid]){
            minEle = min(minEle, nums[mid]);
            high = mid - 1;
        }
    }

    return minEle;
}

int main(){
    vector<int> nums = {3, 4, 5, 6, 6, 3, 3, 3};
    cout<<findMin(nums)<<"\n";
    cout<<findMinBinarySearch(nums)<<"\n";
    return 0;
}