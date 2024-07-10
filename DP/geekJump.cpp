#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*Geek wants to climb from the 0th stair to the (n-1)th stair. At a time the Geek can climb either one or two steps. A height[N] array is also given. 
Whenever the geek jumps from stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. 
return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1.*/

// recursion===============================================================================================
int minEnergyJumpsRecur(int ind, vector<int> &height){ // T.C. = O(2^n)
    if(ind == 0) return 0;

    int one = minEnergyJumpsRecur(ind - 1, height) + abs(height[ind] - height[ind - 1]);
    int two = INT_MAX;
    if(ind > 1){
        two = minEnergyJumpsRecur(ind - 2, height) + abs(height[ind] - height[ind - 2]);
    }

    return min(one, two);
}

// memoization========================================================================================
int minEnergyJumps(int ind, vector<int> &height, vector<int> &dp){    // T.C. = O(n), S.C. = O(n) + O(n) {stack space + dp array space}
    // if(ind == 0) return 0;

    // int one = (dp[ind - 1] == -1 ? minEnergyJumps(ind - 1, height, dp) : dp[ind - 1]) + abs(height[ind] - height[ind - 1]);
    // int two = INT_MAX;
    // if(ind > 1){
    //     two = (dp[ind - 2] == -1 ? minEnergyJumps(ind - 2, height, dp) : dp[ind - 2]) + abs(height[ind] - height[ind - 2]);
    // }

    // return dp[ind] = min(one, two);

    if(ind == 0) return 0;
    if(dp[ind] != -1) return dp[ind];

    int one = minEnergyJumps(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
    int two = INT_MAX;
    if(ind > 1){
        two = minEnergyJumps(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);
    }

    return dp[ind] = min(one, two);
}

// tabulation=============================================================================
int minEnergyJumps2(int ind, vector<int> &height){
    int n = height.size();
    vector<int> dp(n, -1);
    dp[0] = 0;
    dp[1] = abs(height[1] - height[0]);
    for(int i = 2; i < n; i++){
        int one = dp[i - 1] + abs(height[i] - height[i - 1]);
        int two = dp[i - 2] + abs(height[i] - height[i - 2]);
        
        dp[i] = min(one, two);
    }
    
    return dp[n - 1];
}

int minEnergyJumps3(int ind, vector<int> &height){
    int n = height.size();
    // if(n == 1) return 0;
    // int prev2 = 0, prev = abs(height[1] - height[0]);
    // int res = prev;
    // for(int i = 2; i < n; i++){
    //     res = min((prev + abs(height[i] - height[i - 1])), (prev2 + abs(height[i] - height[i - 2])));
    //     prev2 = prev;
    //     prev = res;
    // }
    // return res;

    int prev2 = 0;
    int prev = 0;
    for(int i = 1; i < n; i++){
        int one = prev + abs(height[i] - height[i - 1]);
        int two = INT_MAX;
        if(i > 1){
            two = prev2 + abs(height[i] - height[i - 2]);
        }
        
        int curr = min(one, two);
        prev2 = prev;
        prev = curr;
    }
    
    return prev;
}

int main(){
    vector<int> height = {30, 10, 60, 10, 60, 50};
    int n = height.size();
    
    vector<int> dp(n , -1);
    cout<<minEnergyJumps(n - 1, height, dp)<<"\n";
    cout<<minEnergyJumpsRecur(n - 1, height)<<"\n";
    cout<<minEnergyJumps2(n - 1, height)<<"\n";
    cout<<minEnergyJumps3(n - 1, height)<<"\n";
    return 0;
}