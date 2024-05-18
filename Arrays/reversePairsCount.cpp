#include <iostream>
#include <vector>
using namespace std;

int count = 0;

void merge(vector<int> &nums, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while(left <= mid && right <= high){
        if(nums[left] > (long long)2*(long long)nums[right]){
            right++;
            count += (mid - left + 1);
        }else{
            left++;
        }
    }

    left = low, right = mid + 1;
    while(left <= mid && right <= high){
        if(nums[left] <= nums[right]){
            temp.push_back(nums[left]);
            left++;
        }else{
            temp.push_back(nums[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(nums[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(nums[right]);
        right++;
    }

    for(int i = low; i <= high; i++){
        nums[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &nums, int low, int high){
    if(low >= high) return;
    int mid = (low + high)/2;

    mergeSort(nums, low, mid);
    mergeSort(nums, mid+1, high);
    merge(nums, low, mid, high);

    // return count;
}

// OPTIMAL=================================================================================

int reversePairs2(vector<int>& nums) {
    mergeSort(nums, 0, nums.size()-1);
    return count;
}

// BRUTE=====================================================================
int reversePairs(vector<int> &nums){
    int count = 0;

    for(int i = 0; i < nums.size(); i++){
        for(int j = i + 1; j < nums.size(); j++){
            if(nums[i] > (long long)2*(long long)nums[j]){
                count++;
            }
        }
    }

    return count;
}

int main(){
    vector<int> nums = {1, 3, 2, 3, 1};
    cout<<reversePairs(nums)<<"\n";

    nums = {1, 3, 2, 3, 1};
    cout<<reversePairs2(nums)<<"\n";

    return 0;
}