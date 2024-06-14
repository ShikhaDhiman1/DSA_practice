#include <iostream>
using namespace std;

double power(double x, int n){
    if(n == 0) return 1;
    if(n == 1) return x;

    if(n < 0){
        x = 1/x;
        n = abs(n);
    }

    if(n % 2 == 0) return power(x * x, n / 2);
    return x * power(x, n - 1);
}

double power2(double x, int n){
    if(n == 0) return 1;
    if(n == 1) return x;

    double ans = 1;
    long long m = abs(n);
    while(m){
        if(m % 2 == 0){
            x = x * x;
            m = m / 2;
        }
        else{
            ans = ans * x;
            m = m - 1;
        }
    }
    if(n < 0) return ((double)(1.0) / (double)ans);
    return ans;
}

int main(){
    double x = 1.25;
    int n = 10;
    cout<<power(x, n)<<"\n";
    cout<<power2(x, n)<<"\n";
    return 0;
}