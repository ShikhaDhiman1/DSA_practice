#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &arr, int start, int end){
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
    return;
}

void rotateLeft(vector<int> &arr, int k){
    int n = arr.size();
    if(n == 1) return;

    while(k >= n) k = k % n;

    reverse(arr, 0, k-1);
    reverse(arr, k, n-1);
    reverse(arr, 0, n-1);
}
int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 9;

    rotateLeft(nums, k);

    for(auto x : nums){
        cout<<x<<" ";
    }
    cout<<"\n";
    
    return 0;
}