#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n){
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0){
            return false;
		}
	}
	return true;
}

int main() {
	int n;
    cout<<"Enter the number: ";
	cin>>n;
	
	if(n != 1 && isPrime(n)){
        cout<<"Prime\n";
    }else{
        cout<<"Not Prime\n";
    }

	return 0;
	
}