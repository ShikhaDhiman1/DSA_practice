#include <iostream>
#include <vector>
#include <algorithm>
// #include <bits/stdc++.h>
using namespace std;

int mostFrequent(vector<int> &nums, int k){
    if(nums.empty()) return 0;

    long long winTotal = 0;
    int maxFreq = 0;
    int Left = 0;

    sort(nums.begin(), nums.end());

    for(int Right = 0; Right < nums.size(); Right++){
        winTotal += nums[Right];

        // if current number * window size > current window total + k ==> we cannot make all numbers equal to current number in current window
        // thus, remove leftmost element
        while((long long)nums[Right] * (Right - Left + 1) > winTotal + k){
            winTotal -= nums[Left];
            Left++;
        }
        // else ==> we can make all numbers equal to current number in current window
        // thus, increase the frequency of current number
        maxFreq = max(maxFreq, Right - Left + 1);
    }

    return maxFreq;
}

int main(){
    return 0;
}