#include <iostream>
using namespace std;

void n2Forest(int n){
    for(int i = 1; i <= n; i++){
		for(int j = 0; j < i; j++){
			cout<<"* ";
		}
		cout<<endl;
	}
}

int main(){
    n2Forest(5);
    return 0;
}