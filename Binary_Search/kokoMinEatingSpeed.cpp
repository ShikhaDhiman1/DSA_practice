#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

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
    cout<<ceil((float)(312884470)/(float)(312884469))<<"\n";
    return 0;
}