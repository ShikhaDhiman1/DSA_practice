#include <iostream>
using namespace std;

void print(int n){
    if(n == 0) return;
    cout<<n<<" ";
    print(n-1);
}

void printN(int n){
    if(n == 0) return;
    printN(n-1);
    cout<<n<<" ";
}

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"\nNumbers from "<<n<<" to 1:  \n";
    print(n);
    cout<<"\n\nNumbers till "<<n<<": \n";
    printN(n);
    cout<<endl<<endl;
    return 0;
}