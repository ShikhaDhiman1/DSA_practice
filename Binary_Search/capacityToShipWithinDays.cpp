#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

/*A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the 
conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.*/

int possibleDays(vector<int> &weights, int capacity){
    int load = 0;
    int days = 0;

    for(int i = 0; i < weights.size(); i++){
        if(load + weights[i] > capacity){
            load = weights[i];
            days++;
        }
        else{
            load += weights[i];
        }
    }
    if(load <= capacity) days++;

    return days;
}

int shipWithinDays(vector<int> &weights, int days){
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    int ans = -1;

    // BRUTE force
    // for(int i = low; i <= high; i++){
    //     if(possibleDays(weights, i) <= days){
    //         return i;
    //     }
    // }

    // OPTIMAL using BINARY search
    while(low <= high){
        int mid = (low + high)/2;

        if(possibleDays(weights, mid) <= days){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    return 0;
}