#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. 
Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.*/

int result(vector<int> &nums, int divisor){
    int result = 0;

    for(auto x : nums){
        result += ceil((double)x / (double)divisor);
    }
    return result;
}
int smallestDivisor(vector<int> &nums, int threshold){
    int low = 1, high = *max_element(nums.begin(), nums.end());

    while(low <= high){
        int mid = (low + high)/2;

        if(result(nums, mid) <= threshold){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> nums = {44, 22, 33, 11, 1};
    int thresh = 5;
    cout<<smallestDivisor(nums, thresh)<<"\n";
    return 0;
}