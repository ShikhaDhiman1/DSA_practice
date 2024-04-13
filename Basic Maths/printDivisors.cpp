#include <iostream>
#include <cmath>
using namespace std;

static int size = 0;

int* printDivisors(int n) {
    int* res = new int[n/2 + 1];
    for(int i = 1; i <= n/2; i++){
        if(n % i == 0){
            res[size] = i;
            size++;
        }
    }
    res[size] = n;

    return res;
}
void printAllDivisors(int n){
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            cout<<i<<" ";
            if( i != n/i){
                cout<<(n/i)<<" ";
            }
        }
    }
    cout<<endl<<endl;
    return;
}
int main(){
    int* ans = new int[size+1];
    ans = printDivisors(210);
    for(int i = 0; i <= size; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl<<endl;    
    printAllDivisors(100);
    return 0;
}