#include <iostream>
#include<vector>
using namespace std;

int maxConsecutiveOnes(vector<int> &nums, int k){
    int maxOnes = 0;
    int n = nums.size();

    for(int i = 0; i < n; i++){
        int count = 0;
        int j;
        for(j = i; j < n; j++){
            if(nums[j] == 0) count++;
            if(count > k){
                maxOnes = max(maxOnes, j - i);
                break;
            }
        }
        maxOnes = max(maxOnes, j - i);
    }

    return maxOnes;
}

int maxConsecutiveOnes2(vector<int> &nums, int k){
    // int l = 0, r = 0;
    // int maxOnes = 0;
    // int count = 0;

    // while(r < nums.size()){
    //     if(nums[r] == 0) count++;
    //     if(count > k){
    //         maxOnes = max(maxOnes, r - l);
    //         if(nums[l] == 0){
    //             count--;
    //         }
    //         l++;
    //     }
    //     r++;
    // }
    // maxOnes = max(maxOnes, r - l);

    // return maxOnes;

    // OR===============================================================
    // int l = 0, r = 0;
    // int maxOnes = 0;
    // int count = 0;

    // while(r < nums.size()){
    //     if(nums[r] == 0) count++;
    //     if(count <= k){
    //         maxOnes = max(maxOnes, r - l + 1);
    //     }
    //     else{
    //         if(nums[l] == 0){
    //             count--;
    //         }
    //         l++;
    //     }
    //     r++;
    // }

    // return maxOnes;

    // OR==============================================
    int l = 0, r = 0;
    int maxOnes = 0;
    int zeroes = 0;

    while(r < nums.size()){
        if(nums[r] == 0) zeroes++;

        while(zeroes > k){
            if(nums[l] == 0) zeroes--;
            l++;
        }
        if(zeroes <= k){
            maxOnes = max(maxOnes, r - l + 1);
        }
        r++;
    }
    return maxOnes;
}

int main(){
    vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 4;
    cout<<maxConsecutiveOnes(nums, k)<<"\n";
    cout<<maxConsecutiveOnes2(nums, k)<<"\n";
    return 0;
}