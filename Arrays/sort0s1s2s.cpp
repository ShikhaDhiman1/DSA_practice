#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void sort012(vector<int> &nums){
    //T.C. = O(n) + O(n) = O(2n)
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for(int  i = 0; i < nums.size(); i++){
        if(nums[i] == 0) cnt0++;
        else if(nums[i] == 1) cnt1++;
        else cnt2++;
    }
    int  i = 0;
    while(cnt0){
        nums[i] = 0;
        i++;
        cnt0--;
    }
    while(cnt1){
        nums[i] = 1;
        i++;
        cnt1--;
    }
    while(cnt2){
        nums[i] = 2;
        i++;
        cnt2--;
    }

    // OR:---->>>>>>>>>>
    // for(int i = 0; i < cnt0; i++){
    //     nums[i] = 0;
    // }
    // for(int i = cnt0; i < cnt0 + cnt1; i++){
    //     nums[i] = 1;
    // }
    // for(int i = cnt0 + cnt1; i < nums.size()-1; i++){
    //     nums[i] = 2;
    // }
}

void sortArray012(vector<int> &nums){
    // DUTCH NATIONAL FLAG algorithm

    //T.C. = O(n)
    int left = 0, mid = 0, high = nums.size()- 1;

    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[left], nums[mid]);
            left++;
            mid++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main(){
    vector<int> arr = {2, 0, 1, 2, 0, 0, 2, 1, 1, 1, 0, 2, 0};
    sort012(arr);
    for(auto x : arr){
        cout<<x<<" ";
    }
    cout<<"\n";

    arr = {2, 0, 1, 2, 0, 0, 2, 1, 1, 1, 0, 2, 0};
    sortArray012(arr);
    for(auto x : arr){
        cout<<x<<" ";
    }
    cout<<"\n";

    return 0;
}