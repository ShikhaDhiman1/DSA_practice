#include <iostream>
#include <vector>
using namespace std;

// BRUTE force
int singleNonDulicate(vector<int> &nums){
    int n = nums.size();
    if(n == 1) return nums[0];

    for(int i = 0; i < n - 1; i += 2){
        if(nums[i] != nums[i + 1]){
            return nums[i];
        }
    }
    return nums[n - 1];
}

// OPTIMAL --> Using BINARY search
int singleNonDuplicate2(vector<int> &nums){
    int n = nums.size();

    if(n == 1) return nums[0];
    if(nums[0] != nums[1]) return nums[0];
    if(nums[n - 1] != nums[n - 2]) return nums[n - 1];

    int left = 1, right = n - 2;

    while(left <= right){
        int mid = (left + right)/2;

        if(nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1]) return nums[mid];

        // (even, odd) ==> (mid - 1, mid) || (mid, mid + 1) ----> in left subarray
        if((mid % 2 == 1 && nums[mid - 1] == nums[mid]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1])){
            // eliminate left half {, i.e., left half doesn't contain single element}
            left = mid + 1;
        }
        else{
            // eliminate right half
            right = mid - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    cout<<singleNonDulicate(nums)<<"\n";
    cout<<singleNonDuplicate2(nums)<<"\n";
    return 0;
}