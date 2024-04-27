#include <iostream>
#include <vector>
using namespace std;

void printSubarrWithMaxSum(vector<int> &nums){
    int sum = 0;
    int maxSum = nums[0];

    int start = 0, end = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        if(sum >= maxSum){
            maxSum = sum;
            end = i;
        }
        if(sum < 0){
            sum = 0;
            start = i+1;
        }
    }
    cout<<start<<", "<<end<<"\n";
    cout<<"Subarray with maximum sum is :\n";
    for(int j = start; j <= end; j++){
        cout<<nums[j]<<" ";
    }
    cout<<"\n";
    return;
}

int main(){
    vector<int> arr = {-1, 9, -7, -4, 10, 4, -2, 0, 2, -2};
    printSubarrWithMaxSum(arr);
    return 0;
}