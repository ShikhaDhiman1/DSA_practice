#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Given an ascending sorted rotated array arr of distinct integers of size n. 
// The array is right-rotated k times. Find the value of k.

// SOLUTION:->  k = index of minimum element in the array

// BRUTforce approach :-> linear search

int findkRotationBrute(vector<int> &arr){
    int index = 0;
    int minEle = INT_MAX;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] < minEle){
            minEle = arr[i];
            index = i;
        }
    }
    return index;
}

int findkRotation(vector<int> &arr){
    int n = arr.size();
    if(arr[0] < arr[n - 1]){
        return 0;
    }
    int pivot = 0;
    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i + 1]){
            pivot = i;
            break;
        }
    }
    return pivot+1;
}

int findkRotationBinarySearch(vector<int> &arr){    //  USING Binary Search
    int low = 0, high = arr.size()- 1;

    int minEle = INT_MAX;
    int index = 0;

    while(low <= high){
        int mid = (low + high)/2;

        if(arr[low] < arr[high]){
            if(arr[low] < minEle){
                return low;
            }
        }
        if(arr[low] <= arr[mid]){
            if(arr[low] < minEle){
                minEle = arr[low];
                index = low;
            }
            low = mid + 1;
        }
        else if(arr[high] > arr[mid]){
            if(arr[mid] < minEle){
                minEle = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}

int main(){
    vector<int> arr = {4, 5, 6, 7, 1, 2, 3};
    cout<<findkRotationBrute(arr)<<"\n";
    cout<<findkRotation(arr)<<"\n";
    cout<<findkRotationBinarySearch(arr)<<"\n";
    return 0;
}