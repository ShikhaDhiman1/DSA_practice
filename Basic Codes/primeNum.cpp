#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int n){  // prime number is a positive number
    if(n <= 1) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if( n % i == 0) return false;
    }
    return true;
}

int main(){
    int num;
    cout<<"Enter the number to be checked as a prime number: ";
    cin>>num;
    if(isPrime(num)) cout<<"\n"<<num<<" is a prime number.\n\n";
    else cout<<"\n"<<num<<" is not a prime number.\n\n";
    return 0;
}