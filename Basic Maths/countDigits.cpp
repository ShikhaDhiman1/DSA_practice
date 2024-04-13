#include <iostream>
#include <cmath>
using namespace std;

int countDigits(int n){
    int count = 0;

    while(n > 0){
        n = floor(n/10);
        count++;
    }
    return count;
}

int main(){
    cout<<"Digits in '12345' : "<<countDigits(12345);
    cout<<endl;
    return 0;
}