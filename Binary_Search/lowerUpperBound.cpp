#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> findFloorCeil(vector<int> &arr, int x){
    sort(arr.begin(), arr.end());
    int left = 0; 
    int right = arr.size() - 1;

    int lower = -1, upper = -1;

    while(left <= right){
        int mid = left + (right - left)/2;

        if(arr[mid] == x) return {x, x};
        else if(arr[mid] < x){
            lower = arr[mid];
            left = mid + 1;
        }
        else{
            upper = arr[mid];
            right = mid - 1;
        }
    }
    return {lower, upper};
}

int main(){
    vector<int> arr = {9, 5, 8, 6, 5, 9, 6, 5, 5, 6};
    pair<int, int> ans = findFloorCeil(arr, 7);
    cout<<ans.first<<", "<<ans.second<<"\n";
    return 0;
}