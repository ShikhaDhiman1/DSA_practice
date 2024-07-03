#include <iostream>
#include <vector>
using namespace std;

/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.*/

int trap(vector<int> &height){
    int n = height.size();
    vector<int> prefix(n);
    vector<int> suffix(n);

    prefix[0] = height[0];
    suffix[n - 1] = height[n - 1];

    for(int i = 1; i < n; i++){
        if(height[i] > prefix[i - 1]){
            prefix[i] = height[i];
        }else{
            prefix[i] = prefix[i - 1];
        }
    }

    for(int i = n - 2; i >= 0; i--){
        if(height[i] > suffix[i + 1]){
            suffix[i] = height[i];
        }
        else{
            suffix[i] = suffix[i + 1];
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += (min(prefix[i], suffix[i]) - height[i]);
    }
    return ans;
}

int trap2(vector<int> &height){
    int l = 0;
    int r = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    int ans = 0;

    while(l < r){
        if(height[l] <= height[r]){
            if(height[l] >= leftMax){
                leftMax = height[l];
            }else{
                ans += (leftMax - height[l]);
            }
            l++;
        }
        else{
            if(height[r] >= rightMax){
                rightMax = height[r];
            }else{
                ans += (rightMax - height[r]);
            }
            r--;
        }
    }

    return ans;
}

int main(){
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3,2, 1, 2, 1, 0};

    cout<<trap(height)<<"\n";
    cout<<trap2(height)<<"\n";

    return 0;
}