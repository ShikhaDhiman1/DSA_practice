#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int factorial(int n){
        int fact = 1;
        for(int i = 1; i < n+1; i++){
            fact *= i;
        }
        cout<<"fact "<<fact<<endl;
        return fact;
    }
    int nCr(int n, int r){
        return factorial(n)/(factorial(r) * factorial(n-r));
        // code here
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        Solution ob;
        cout<<"nCr "<<ob.nCr(n,r);
        cout<<endl;
    }
    return 0;
}