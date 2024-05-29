#include <iostream>
using namespace std;

int floorSqrt(int n){
    if(n == 0 || n == 1){
        return n;
    }
    int i = 1, result = 1;
    while(result <= n){
        i++;
        result = i*i;
    }
    return i-1;
}

int floorSqrt2(int n){
    int ans = 1;
    for(int i = 1; i <= n; i++){
        if(i * i <= n){
            ans = i;
        }
        else break;
    }
    return ans;
}

int floorSqrtBS(int n){
    int ans = 1;
    int low = 1, high = n;

    while(low <= high){
        int mid = (low + high)/2;

        if((mid * mid) <= n){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    cout<<floorSqrt(4)<<"\n";
    cout<<floorSqrt2(4)<<"\n";
    cout<<floorSqrtBS(4)<<"\n";
    return 0;
}