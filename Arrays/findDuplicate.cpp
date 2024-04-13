#include <iostream>
using namespace std;

int duplicate(int * arr, int n){
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = ans ^ arr[i];
        cout<<ans<<" ";
    }
    cout<<endl;
    for(int j = 1; j < n; j++){
        ans = ans ^ j;
        cout<<ans<<" ";
    }
    cout<<endl;
    return ans;
}

int main(){
    int arr[8]  = {1,1,2,3,4,5,6,6};
    cout<<duplicate(arr, 8)<<endl;

    return 0;
}