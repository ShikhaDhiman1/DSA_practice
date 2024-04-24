#include <iostream>
#include <vector>
using namespace std;

int maxConsecutiveOnes(vector<int> &nums){
    int maxOnes = 0;
    int ones = 0;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 1){
            ones += 1;
        }
        else{
            maxOnes = max(maxOnes, ones);
            ones = 0;
        }
    }
    return max(maxOnes, ones);
}

int maxConsecutiveOnes2(vector<int> vehicle, int m){
    int left = 0;
    int maxLen = 0;
    int zeros = 0;

    for(int right = 0; right < vehicle.size(); right++){
        if(vehicle[right] == 0){
            zeros++;
        }
        while(zeros > m){
            if(vehicle[left] == 0){
                zeros--;
            }
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main(){
    vector<int> arr = {0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0};
    cout<<maxConsecutiveOnes(arr)<<"\n";
    cout<<maxConsecutiveOnes2(arr, 3)<<"\n";
    return 0;
}