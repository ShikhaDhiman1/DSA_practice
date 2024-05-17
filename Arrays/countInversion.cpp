#include <iostream>
#include <vector>
using namespace std;

int count = 0; // to be used in the optimal appraoch

// BRUTE APPROACH==============================================
int inversionCount(vector<int> &arr){
    int n = arr.size();
    int inversion = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]){
                inversion++;
            }
        }
    }
    return inversion;
}

// OPTIMAL approach =======================================================

// void merge(vector<int>& arr, int low, int mid, int high){
//     vector<int> temp;
//     int left = low;
//     int right = mid + 1;

//     while(low <= mid && right <= high){
//         if(arr[left] > arr[right]){
//             temp.push_back(arr[right]);
//             right++;
//             count += mid -left + 1;
//         }else{
//             temp.push_back(arr[left]);
//             left++;
//         }
//     }
//     while(left <= mid){
//         temp.push_back(arr[left]);
//         left++;
//     }
//     while(right < high){
//         temp.push_back(arr[right]);
//         right++;
//     }

//     for(int i = low; i <= high; i++){
//         arr[i] = temp[i - low];
//     }
// }
// int mergeSort(vector<int> &arr, int low, int high){
//     if(low >= high) count;

//     int mid = (low + high)/2;

//     mergeSort(arr, low, mid);
//     mergeSort(arr, mid + 1, high);
//     merge(arr, low, mid, high);
    
//     return count;
// }

// int inversionCount2(vector<int> &arr){
//     int n = arr.size();
//     return mergeSort(arr, 0, n-1);
// }

int main(){
    vector<int> nums = {2, 4, 1, 3, 5};
    nums = {2, 3, 4, 5, 6};
    cout<<inversionCount(nums)<<"\n";
    cout<<inversionCount2(nums)<<"\n";
    return 0;
}