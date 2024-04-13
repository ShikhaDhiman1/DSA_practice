#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int n1, int n2){
    if(n2 == 0){
        return n1;
    }

    gcd(n2, n1 % n2);
}

int main(){
    int a, b;
    cout<<"Enter the value a and b: ";
    cin>>a>>b;
    cout<<"GCD(or HCF) of "<<a<<" and "<<b<<" is : "<<gcd(a, b)<<endl;

    int arr[4] = {513, 1134, 1215, 81};
    // int arr[3] = {513, 1134, 1215};
    sort(arr, arr + 3);
    for(int i = 0; i < 4; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int n1 = arr[0];
    int n2 = arr[1];
    int ans = gcd(n1, n2);
    for(int i = 2; i < 4; i+=2){
        ans = gcd(arr[i], ans);

    }
    cout<<ans<<endl;
    return 0;
}