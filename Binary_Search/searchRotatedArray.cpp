#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int target, int low, int high){
    if(low > high) return -1;
    int mid = (low + high)/2;

    if(nums[mid] == target) return mid;
    else if(nums[mid] < target){
        return binarySearch(nums, target, mid + 1, high);
    }
    return binarySearch(nums, target, low, mid - 1);
}

int search2(vector<int> &nums, int target){
    int n = nums.size();
    int pivot = -1;

    for(int i = 0; i < n - 1; i++){
        if(nums[i] > nums[i + 1]){
            pivot = i;
            break;
        }
    }

    if(pivot == -1){
        return binarySearch(nums, target, 0, n-1);
    }

    int ans = binarySearch(nums, target, 0, pivot);
    if(ans != -1){
        return ans;
    }
    return binarySearch(nums, target, pivot + 1, n-1);
}

int search(vector<int> &nums, int target){
    int low = 0, high = nums.size() - 1;

    while(low <= high){
        int mid = (low + high)/2;

        if(nums[mid] == target) return mid;
        else if(nums[low] <= nums[mid]){
            if(nums[low] <= target && target <= nums[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(nums[mid] <= target && target <= nums[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout<<search(nums, target)<<"\n";
    cout<<search2(nums, target)<<"\n";
    return 0;
}