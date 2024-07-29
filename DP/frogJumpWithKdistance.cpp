#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minEnergyRecur(int ind, vector<int> &height, int k){
    if(ind == 0) return 0;

    int minCost = INT_MAX;
    for(int i = 1; i <= k; i++){
        if(ind - i >= 0){
            int cost = minEnergyRecur(ind - i, height, k) + abs(height[ind] - height[ind - i]);
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}

int minEnergyMemo(int ind, vector<int> &height, int k, vector<int> &dp){ // T.C.=O(n * k), S.C. = O(n) + O(n)
    if(ind == 0) return 0;
    if(dp[ind] != -1) return dp[ind];

    int minCost = INT_MAX;

    for(int i = 1; i <= k; i++){
        if(ind - i >= 0){
            int cost = minEnergyMemo(ind - i, height, k, dp) + abs(height[ind] - height[ind - i]);
            minCost = min(minCost, cost);
        }
    }
    return dp[ind] = minCost;
}

int minEnergyTabu(vector<int> &height, int n, int k){ // T.C.=O(n * k), S.C. = O(n)
    vector<int> dp(n);
    dp[0] = 0;

    for(int i = 1; i < n; i++){
        int minCost = INT_MAX;
        for(int j = 1; j <= k; j++){
            if(i - j >= 0){
                int cost = dp[i - j] + abs(height[i] - height[i - j]);
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }

    return dp[n - 1];
}

int main(){
    vector<int> height = {10, 30, 40, 50, 20};
    int k = 3, n = 5;

    cout<<minEnergyRecur(n - 1, height, k)<<"\n";
    vector<int> dp(n, -1);
    cout<<minEnergyMemo(n - 1, height, k, dp)<<"\n";
    cout<<minEnergyTabu(height, k, n)<<"\n";

    return 0;
}