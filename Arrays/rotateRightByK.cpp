#include <iostream>
#include <vector>
using namespace std;

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
    for(int i = 0; i < (n-k)/2; i++){
        // int temp = arr[i];
        // arr[i] = arr[k-i];
        // arr[k-i] = temp;

        swap(arr[i], arr[k-i]);
    }

    for(int i = n-k; i < n/2; i++){
        // int temp = arr[i];
        // arr[i] = arr[n-1-i];
        // arr[n-1-i] = temp;

        swap(arr[i], arr[n-1-i]);
    }

    for(int i = 0; i < n/2; i++){
        // int temp = arr[i];
        // arr[i] = arr[n-1-i];
        // arr[n-1-i] = arr[i];

        swap(arr[i], arr[n-1-i]);
    }

    return;
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 7;

    rotateK(nums, k);

    for(auto x : nums){
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}