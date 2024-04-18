#include <iostream>
#include <vector>
using namespace std;

void insertSort(vector<int> &arr){
    for(int i = 1; i < arr.size(); i++){
        int key = arr[i];
        int j = i-1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }

    return;
}

void insertSort2(vector<int> &arr){
    for(int i = 0; i < arr.size(); i++){

        int j = i;

        while(j>0 && arr[j-1] > arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;

            j--;
        }
    }
    return;
}

int main(){
    vector<int> nums = {9, 3, 19, 0, 5, 12, 1, 0};

    insertSort(nums);

    cout<<"\n";
    for(auto x : nums){
        cout<<x<<" ";
    }
    cout<<"\n\n";
    
    vector<int> nums2 = {10, 5, 7, 2, 1, 9, 0, 3};
    insertSort2(nums2);

    cout<<"\n";
    for(auto x : nums2){
        cout<<x<<" ";
    }
    cout<<"\n\n";

    return 0;
}