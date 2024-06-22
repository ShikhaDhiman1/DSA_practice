#include <iostream>
using namespace std;

int fact(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return n*fact(n-1);
}

int main(){
     int n;
    cout<<"Enter the Number for which you need the factorial: ";
    cin>>n;
    cout<<"\nFactorial of "<<n<<" is : "<<fact(n);
    cout<<endl<<endl;
    return 0;   
}