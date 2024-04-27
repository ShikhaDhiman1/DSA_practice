#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int bestTimeToBuyAndSellStock(vector<int> &prices){
    int buyDay = 0;
    int minPrice = prices[0];

    int maxProfit = 0;
    int left = 0;
    int right = 0;
    for(; right < prices.size(); right++){
        int x = prices[right] - prices[left];
        maxProfit  = max(maxProfit, x);

        if(x < 0){
            left = right;
        }
    }
    if(maxProfit){
        cout<<"Best Day to bus stock is : "<<left+1<<"\n";
        cout<<"Best day to sell stock is : "<<right<<"\n";
    }
    else{
        cout<<"Stocks can be bought and sold on same day ony!\n";
    }
    return maxProfit;
}

int main(){
    vector<int> prices = {7, 1, 5, 4, 3, 6};
    // prices = {5, 4, 3, 2, 1};
    cout<<"Maximum profit is : "<<bestTimeToBuyAndSellStock(prices)<<"\n";
    return 0;
}