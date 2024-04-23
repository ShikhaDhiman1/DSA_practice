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

int main(){
    vector<int> arr = {0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0};
    cout<<maxConsecutiveOnes(arr)<<"\n";
    return 0;
}