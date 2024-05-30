#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile 
has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.*/

int minEatingSpeed(vector<int> &piles, int h){
    int speed = 1;

    while(true){
        int count = 0;
        // cout<<"Speed "<<speed<<"\n";
        for(int i = 0; i < piles.size(); i++){
            // cout<<ceil(piles[i]/speed)<<", ";
            count += ceil((float)piles[i]/(float)speed);
        }
        if(count == h) break;
        speed++;
        // cout<<"\n";
    }

    return speed;
}

int main(){
    vector<int> piles = {3, 6, 7, 11};
    cout<<minEatingSpeed(piles, 8);
    return 0;
}