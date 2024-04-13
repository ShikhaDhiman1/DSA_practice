#include <iostream>
#include <cmath>
using namespace std;

int reverse(int n){
    int num = 0;

    while(n > 0){
        int digit = n%10;
        num = digit + num*10;
        n = floor(n/10);
    }
    return num;
}

int main(){
    int n;
    cout<<"Enter the number to be reversed: ";
    cin>>n;
    cout<<"Reverse of "<<n<<" : "<<reverse(n)<<endl;
    return 0;
}