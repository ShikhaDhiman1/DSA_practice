#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int> &nums, int n, int x){
    int low = 0, high = n-1;
    int ans = 0;
    while(low <= high){
        int mid = (low + high)/2;

        if(nums[mid] >= x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int rowWithMax1s2(vector<vector<int>> &arr, int n, int m){
    int maxOnes = 0;
    int row = -1;
    for(int i = 0; i < n; i++){
        int countOnes = m - lowerBound(arr[i], m, 1);
        if(countOnes > maxOnes){
            maxOnes = countOnes;
            row = i;
        }
    }
    return row;
}

int rowWithMax1s(vector<vector<int>> &arr, int n, int m){
    int row = -1;
    int maxOnes = 0;
    for(int i = 0; i < n; i++){
        int low = 0, high = m-1;
        int countOnes = 0;
        while(low <= high){
            int mid = (low + high)/2;
            
            if(arr[i][mid] == 1){
                countOnes += high - mid + 1;
                high = mid - 1;
            }
            else if(arr[i][mid] == 0){
                low = mid + 1;
            }
        }
        if(countOnes > maxOnes){
            maxOnes = countOnes;
            row = i;
        }
    }
    return row;
}

int main(){
    vector<vector<int>> arr = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}};

    cout<<rowWithMax1s(arr, 4, 4)<<"\n";
    cout<<rowWithMax1s2(arr, 4, 4)<<"\n";
    return 0;
}