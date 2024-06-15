#include <iostream>
using namespace std;

const long long mod = 1e9 + 7;

int power(long long a, long long b){
    if(b == 0) return 1;

    if(b % 2 == 0){
        return power((a * a) % mod, b / 2);
    }

    return (a * (power(a, b - 1)) % mod) % mod;
}

int countGoodNumbers(long long n){
    long long even = 0, odd = 0;

    if(n % 2 == 0){
        even = n / 2;
        odd = n / 2;
    }
    else{
        even = (n + 1) / 2;
        odd = n / 2;
    }

    return (((power(5, even)) % mod) * ((power(4, odd)) % mod)) % mod;
}

int main(){
    long long int n = 806166225460393;
    cout<<countGoodNumbers(n)<<"\n";
    cout<<countGoodNumbers(4)<<"\n";
    return 0;
}