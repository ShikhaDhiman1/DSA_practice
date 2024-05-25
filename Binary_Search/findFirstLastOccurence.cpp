#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int> &nums, int target){
    int left = 0, right = nums.size() - 1;
    int ans = -1;

    while(left <= right){
        int mid = left + (right - left)/2;

        if(nums[mid] == target){
            ans = mid;
            right = mid - 1;
        }
        else if(nums[mid] > target){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return ans;
}

int lastOccurence(vector<int> &nums, int target){
    int left = 0, right = nums.size() - 1;
    int ans = -1;

    while(left <= right){
        int mid = left + (right - left)/2;

        if(nums[mid] == target){
            ans = mid;
            left = mid + 1;
        }
        else if(nums[mid] > target){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int> &nums, int target){
    return {firstOccurence(nums, target), lastOccurence(nums, target)};
}

int countOccurences(vector<int> &nums, int target){
    int first = firstOccurence(nums, target);
    if(first == -1) return 0;
    int last = lastOccurence(nums, target);

    return (last - first + 1);
}

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    vector<int> ans = searchRange(nums, 7);
    cout<<ans[0]<<", "<<ans[1]<<"\n";
    cout<<"#Occurences: "<<countOccurences(nums,7)<<"\n";
    return 0;
}