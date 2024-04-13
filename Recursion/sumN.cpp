#include <iostream>
using namespace std;

int sumRecur(int n){
    if( n < 1) return 0;

    return (n + sumRecur(n-1));
}

int main(){
    int n;
    cout<<"\nEnter the number of terms: ";
    cin>>n;

    cout<<"\nSum till "<<n<<"th term is = "<<sumRecur(n)<<"\n\n";
    return 0;
}