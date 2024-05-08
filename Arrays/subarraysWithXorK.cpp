#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraysWithXorK(vector<int> &nums, int k){
    int count = 0;

    for(int i = 0; i < nums.size(); i++){
        int xorNum = 0;
        for(int j = i; j < nums.size(); j++){
            xorNum ^= nums[i];
            if(xorNum == k){
                count++;
            }
        }
    }
    return count;
}

int subarraysWithXorK2(vector<int> &nums, int k){
    int count = 0;
    int preXor = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;

    for(int i = 0; i < nums.size(); i++){
        preXor ^= nums[i];

        mp[preXor]++;

        count += mp[preXor^k];
    }
    return count;
}

int main(){
    vector<int> arr = {1, 2, 3, 2};
    int k = 2;
    cout<<subarraysWithXorK2(arr, k)<<"\n";
    cout<<subarraysWithXorK(arr, k)<<"\n";
    
    return 0;
}