#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];

    int i = low;
    int j = high;

    while(i < j){
        while(arr[i] < pivot && i <= high){
            i++; // move i forward until element > pivot is obtained
        }
        while(arr[j] >= pivot && j >= low){
            j--; // move j backward until element <= pivot is found
        }

        if(i < j){
            swap(arr[i], arr[j]); // placing elements smaller than pivot on left and larger ones on the right of pivot
        }
    }
    swap(arr[low], arr[j]); // placing pivot(arr[low]) at it's correct position(,.i.e., at j-th position)

    return j; // return correct position of pivot in the sorted array
}

void quickSort(vector<int> &arr, int low, int high){
    if(low < high){
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
    return;
}

int main(){
    vector<int> arr = {2, 13, 4, 1, 3, 6, 28, 1};

    quickSort(arr, 0, arr.size()-1);

    cout<<"\n";
    for(auto x : arr){
        cout<<x<<" ";
    }
    cout<<"\n\n";
    return 0;
}