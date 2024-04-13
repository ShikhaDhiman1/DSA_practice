#include <iostream>
using namespace std;

void numberCrown(int n) {
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout<<j;
        }
        for(int k = 1; k <= 2*(n-i); k++){
            cout<<" ";
        }
        for(int h = i; h > 0; h--){
            cout<<h;
        }
        cout<<endl;
    }
}

int main(){
    numberCrown(3);
    return 0;
}