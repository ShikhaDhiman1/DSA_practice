#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findTwoElements(vector<int> &arr){
    int n = arr.size();

    int sum = n*(n+1)/2;
    int cumulativeSum = 0;
    unordered_map<int, int> mp;
    vector<int> ans;

    for(auto x : arr){
        mp[x]++;
        if(mp[x] == 2){
            ans.push_back(x);
        }
        else{
            cumulativeSum += x;
        }
    }
    ans.push_back(sum - cumulativeSum);

    return ans;
}

vector<int> findTwoElements2(vector<int> &arr){
    vector<int> ans;
    unordered_map<int, int> mp;
    
    for(int i = 0; i < arr.size(); i++){
        mp[arr[i]]++;
        if(mp[arr[i]] == 2){
            ans.push_back(arr[i]);
        }
    }
    for(int i = 1; i <= arr.size(); i++){
        if(mp[i] == 0){
            ans.push_back(i);
            break;
        }
    }
    return ans;
}

vector<int> findMissingAndRepeatedEle(vector<vector<int>> &grid){
    unordered_map<int, int> mp;
        vector<int> ans;

        int n = grid.size()*grid.size();
        int sum = n*(n+1)/2;

        int cumulativeSum = 0;

        for(auto vec : grid){
            for(auto x : vec){
                mp[x]++;
                if(mp[x] == 2){
                    ans.push_back(x);
                }else{
                    cumulativeSum += x;
                }
            }
        }
        ans.push_back(sum - cumulativeSum);
        return ans;
}

vector<int> findTwoElementsUsingSum(vector<int> &nums){
    int n = nums.size();
    int sn = n*(n+1)/2;
    int s = 0;

    int s2n = n*(n+1)*(2*n+1)/6;
    int s2 = 0;

    for(auto x : nums){
        s += x;
        s2 += x*x;
    }

    int s_sn = s - sn; // x - y
    
    int s2_s2n = s2 - s2n; // x^2 - y^2( == (x-y)(x+y))
    
    int xPlusy = s2_s2n/s_sn; // x + y = (x^2 - y^2)/(x - y)
    
    int x = (s_sn + xPlusy)/2;
    
    int y = xPlusy - x;
    
    return {x, y};
}

vector<int> findTwoElementsUsingXor(vector<int> &arr){
    int n = arr.size();
    int xr = 0;
    for(int i = 0; i < n; i++){
        xr ^= arr[i];
        xr ^= (i+1);
    }
    int bitPos = 0;
    
    while(1){
        if(xr & (1 << bitPos)) break;
        bitPos++;
    }
    
    int zero = 0;
    int one = 0;
    
    for(int i = 0; i < n; i++){
        if(arr[i] & (1 << bitPos)) one ^= arr[i];
        else zero ^= arr[i];
        
        if((i+1) & (1 << bitPos)) one ^= (i + 1);
        else zero ^= (i + 1);
    }
    
    int count = 0;
    
    for(auto x : arr){
        if(zero == x) count++;
        if(count == 2) break;
    }
    
    if(count == 2) return {zero, one};
    return {one, zero};
}

int main(){
    vector<int> nums = {7, 1, 2, 5, 4, 4, 3};
    vector<int> ans1 = findTwoElements(nums);
    vector<int> ans2 = findTwoElements2(nums);

    for(auto x : ans1){
        cout<<x<<" ";
    }
    cout<<"\n";

    for(auto x : ans2){
        cout<<x<<" ";
    }
    cout<<"\n";

    vector<vector<int>> grid = {{9, 1, 2}, {3, 7, 8},{6, 9, 4}};
    vector<int> ans3 = findMissingAndRepeatedEle(grid);
    for(auto x : ans3){
        cout<<x<<" ";
    }
    cout<<"\n";

    nums = {7, 1, 2, 5, 4, 4, 3};
    vector<int> ans4 = findTwoElementsUsingSum(nums);
    for(auto x : ans4){
        cout<<x<<" ";
    }
    cout<<"\n";

    nums = {7, 1, 2, 5, 4, 4, 3};
    vector<int> ans5 = findTwoElementsUsingXor(nums);
    for(auto x : ans5){
        cout<<x<<" ";
    }
    cout<<"\n";

    return 0;
}