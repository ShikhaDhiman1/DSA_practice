#include <iostream>
using namespace std;

void pairSum(int *arr, int n, int sum){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if((arr[i] + arr[j]) == sum){
                count++;
                cout<<arr[i]<<" "<<arr[j]<<endl;
            }
        }
    }
    cout<<"Number of pairs : "<<count<<endl;
    return ;
}

int main(){
    int n, arr[100], sum;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the array: ";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the sum: ";
    cin>>sum;
    cout<<endl;
    cout<<"Pairs with sum = "<<sum<<" are: \n";
    pairSum(arr, n, sum);
    cout<<endl;
    return 0;
}