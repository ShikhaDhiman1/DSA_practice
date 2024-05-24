#include <iostream>
#include <vector>
using namespace std;

int findCeil(vector<int> &arr, int x){
    int left = 0;
    int right = arr.size() - 1;

    int upper = -1;

    while(left <= right){
        int mid = left + (right -left)/2;

        if(arr[mid] == x) return x;
        else if(arr[mid] > x){
            upper = arr[mid];
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return upper;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 6, 6, 7};
    cout<<findCeil(arr, 5)<<"\n";
    return 0;
}