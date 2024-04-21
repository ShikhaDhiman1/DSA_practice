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
}

void rotateK(vector<int> &arr, int k){
    int n = arr.size();
    if(n < 2) return;

    while(k >= n) k = k % n;
    
    // BRUTE FORCE:->
    // while(k > 0){
    //     int x = arr[n-1];
    //     for(int i = n-1; i > 0; i--){
    //         arr[i] = arr[i-1];
    //     }
    //     arr[0] = x;
    //     k--;
    // }

    // BETTER:->
    // vector<int> vec;
    // vec.insert(vec.begin(), arr.begin(), arr.end()-k);
    // arr.erase(arr.begin(), arr.end()-k);
    // arr.insert(arr.end(), vec.begin(), vec.end());

    //OPTIMAL:->
    reverse(arr, 0, n-k-1);
    reverse(arr, n-k, n-1);
    reverse(arr, 0, n-1);
    
    return;
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 9;

    rotateK(nums, k);

    for(auto x : nums){
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}