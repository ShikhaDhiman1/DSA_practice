#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*You are given an integer array bloomDay, an integer m and an integer k.
You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.*/

bool arePossibleDays(vector<int> &bloomDay, int days, int m, int k){
    int count = 0, totalBouquets = 0;

    for(auto x : bloomDay){
        if(x <= days){
            count++;
        }
        else{
            totalBouquets += count/k;
            count = 0;
        }
    }
    totalBouquets += count/k;

    return (totalBouquets >= m);
}
int minDays(vector<int> &bloomDay, int m, int k){
    int mini = INT_MAX, maxi = INT_MIN;

    for(auto x : bloomDay){
        if(x < mini) mini = x;
        if(x > maxi) maxi = x;
    }
    int ans = -1;
    int low = mini, high = maxi;

    while(low <= high){
        int mid = (low + high)/2;

        if(arePossibleDays(bloomDay, mid, m, k)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> bloomDay = {7, 7, 7, 13, 12, 7, 11};
    int bouquets = 2;
    int adjFlowers = 3;
    cout<<minDays(bloomDay, bouquets, adjFlowers)<<"\n";
    return 0;
}