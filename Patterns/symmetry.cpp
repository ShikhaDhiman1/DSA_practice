#include <iostream>
using namespace std;

void symmetry(int n) {
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            cout<<"* ";
        }
        for(int k = 0; k < 2*(n-i); k++){
            cout<<"  ";
        }
        for(int h = 0; h < i; h++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (n-i); j++){
            cout<<"* ";
        }
        for(int h = 0; h < 2*i; h++){
            cout<<"  ";
        }
        for(int h = 0; h < (n-i); h++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main(){
    symmetry(5);
    return 0;
}