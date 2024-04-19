#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(vector<int> &arr){
    for(int i = 1; i < arr.size(); i++){

        bool isSorted = 1;

        // cout<<"Step "<<i<<"\n";

        for(int j = 0; j < arr.size() - i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                isSorted = 0;
            }
        }

        if(isSorted) break;
        
    }
}

int main(){
    vector<int> nums = {2, 13, 4, 1, 3, 6, 28};

    bubbleSort(nums);

    cout<<"\n";
    for(auto x : nums){
        cout<<x<<" ";
    }
    cout<<"\n\n";
    return 0;
}