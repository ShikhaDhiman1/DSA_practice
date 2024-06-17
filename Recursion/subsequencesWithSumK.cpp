#include <iostream>
using namespace std;

long int mod = 1e9 + 7;
int subsetsWithSum(int i, int arr[], int sum){
    if(i < 0){
        if(sum == 0) return 1;
        return 0;
    }

    int pick = 0;
    if(arr[i] <= sum){
        pick = subsetsWithSum(i - 1, arr, sum - arr[i]);
    }
    int notPick = subsetsWithSum(i - 1, arr, sum);

    return (pick + notPick) % mod;
}

int perfectSum(int arr[], int n, int sum){
    return subsetsWithSum(n - 1, arr, sum);
}

int main(){
    int arr[] = {2, 5, 6, 0, 1, 9, 3, 12, 7};
    int n = 9;
    cout<<perfectSum(arr, n, 7)<<"\n";
    return 0;
}