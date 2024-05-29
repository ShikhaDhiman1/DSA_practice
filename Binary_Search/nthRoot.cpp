#include <iostream>
#include <math.h>
using namespace std;

long long int powFunc(int mid, int n, int m){
    long long int ans = 1;

    for(int i = 0; i < n; i++){
        ans *= mid;
        if(ans > m) break;
    }
    return ans;
}

int NthRoot(int n, int m)
{
    if(m == 1 || m == 0 || n == 1) return m;
    int low = 1, high = sqrt(m);
    
    while(low <= high){
        int mid = low + (high - low)/2;
        long long int p = powFunc(mid, n, m);
        if(p == m) return mid;
        else if(p < m){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
} 

int main(){
    cout<<NthRoot(7, 78125)<<"\n";
    return 0;
}