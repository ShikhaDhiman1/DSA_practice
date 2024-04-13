#include <iostream>
using namespace std;

void alphaHill(int n) {
    for(int i = 0; i < n; i++){
        for(int j = n-1; j > i; j--){
            cout<<" ";
        }
        for(int k = 0; k <= i; k++){
            cout<<char(65+k);
        }
        for(int h = i-1; h >= 0; h--){
            cout<<char(65+h);
        }
        cout<<endl;
    }
}

int main(){
    alphaHill(5);
    return 0;
}