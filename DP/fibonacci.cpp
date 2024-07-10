#include <iostream>
#include <vector>
using namespace std;

// T.C. = O(n)
// S.C. = O(n) + O(n) => {stack space + dp array space}

// MEMOIZATION==================================================
int fibbo(int n, vector<int> &dp){
    if(n == 0 || n == 1){
        dp[n] = n;
        return n;
    }
    if(dp[n] != -1) return dp[n];
    return dp[n] = fibbo(n - 1, dp) + fibbo(n - 2, dp);
}

void fibbo2(int n, vector<int> &dp){
    dp[0] = 0, dp[1] = 1;
    for(int i = 2; i < n; i++){
        dp[i] = dp[i -  1] + dp[i - 2];
    }
}

int fibbo3(int n){
    if(n == 0 || n == 1){
        // dp[n] = n;
        return n;
    }
    int first = 0, second = 1;
    int res;
    for(int i = 2; i <= n; i++){
        res = first + second;
        first = second;
        second = res;
    }
    return res;
}

int main(){
    int n = 7;
    vector<int> dp(n + 1, -1);
// using memoization:
    fibbo(n, dp);
    for(int i = 0; i < n; i++){
        cout<<dp[i]<<" ";
    }
    cout<<"\n";
// using tabulation:
    vector<int> dp2(n + 1);
    fibbo2(n, dp2);
    for(int i = 0; i < n; i++){
        cout<<dp2[i]<<" ";
    }
    cout<<"\n";
    cout<<dp2[n-1]<<"\n";

    cout<<fibbo3(n-1)<<"\n";
    cout<<fibbo3(n)<<"\n";
    return 0;
}