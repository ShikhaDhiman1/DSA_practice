#include <iostream>
#include <cmath>
using namespace std;

int sumDivisior(int n){
    cout<<n<<": ";
	if(n == 1) return 1;
	int sum = 0;
	for(int i = 1; i <= n/2; i++){
		if(n % i == 0){
            cout<<i<<" ";
			sum += i;
		}
	}
    cout<<n<<endl<<endl;
	return sum+n;	
}

int sumOfAllDivisors(int n){
	// Write your code here.
	int sum = 0;
	for(int i = 1; i <= n; i++){
		// cout<<sumDivisior(i)<<" ";
		sum += sumDivisior(i);
	}
	
	return sum;
}

int main(){
    int n;
    cout<<ceil(sqrt(10))<<endl;
    cout<<"Enter the number: ";
    cin>>n;

    cout<<sumOfAllDivisors(n)<<endl;
    cout<<endl;
}