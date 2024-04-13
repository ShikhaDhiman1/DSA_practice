#include <iostream>
using namespace std;

int powOfTwo(int n){
    if(n == 0) return 1;
    return 2*powOfTwo(n-1);
}

int main(){
    int n;
    cout<<"Enter the number of terms: ";
    cin>>n;
    cout<<"Power "<<n<<" of 2 is : "<<powOfTwo(n)<<endl<<endl;
    return 0;
}