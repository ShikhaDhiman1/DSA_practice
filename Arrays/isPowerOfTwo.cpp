#include <iostream>
#include <typeinfo>
#include <cmath>
using namespace std;

int power = 0;

bool isPowerTwo(float n){
    if(n==1) return true;
    while( n/2 > 0){
        power++;
        if( (n/2) == 1) return true;
        n = n/2;
    }
    power = 0;
    return false;
}

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    if(isPowerTwo(n)) {
        cout<<"Yes!\n";
        cout<<power<<endl;
    }
    else cout<<"No\n";
    return 0;
}