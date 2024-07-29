#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int getMinCoins(vector<int> &coins, int value){
    int n = coins.size();
    int minCount = INT_MAX;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int sum = coins[i];
            int count = 1;
            for(int k = j; k < n; k++){
                if(sum + coins[k] <= value){
                    sum += coins[k];
                    count++;
                }
                if(sum == value){
                    minCount = min(minCount, count);
                    break;
                }
            }
        }
    }
    return minCount;
}

int main(){
    vector<int> coins = {25, 4, 10, 5, 1};
    int value = 30;
    cout<<getMinCoins(coins, value)<<"\n";
    return 0;
}