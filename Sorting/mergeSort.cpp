#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
    int left = low;
    int right = mid+1;

    vector<int> temp;

    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
}

void merge2(vector<int> &arr, int low, int mid, int high){
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> left(n1);
    vector<int> right(n2);

    for(int i = 0; i < n1; i++){
        left[i] = arr[low + i];
    }

    for(int i = 0; i < n2; i++){
        right[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = low;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = right[j];
        j++;
        k++;
    }
    
}

void mergeSort(vector<int> &arr, int low, int high){
    if(low >= high) return;

    int mid = (low + high)/2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);

    merge2(arr, low, mid, high);
    // merge(arr, low, mid, high);
    
}

int main(){
    vector<int> arr = {2, 13, 4, 1, 3, 6, 28, 1};

    mergeSort(arr, 0, arr.size()-1);

    cout<<"\n";
    for(auto x : arr){
        cout<<x<<" ";
    }
    cout<<"\n\n";
    return 0;
}