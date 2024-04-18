#include <iostream>
#include <vector>
using namespace std;

void insertSort(vector<int> arr){
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
    for(int i = 1; i < arr.size(); i++){
        int j = i;

        while(j-- && arr[j-1] > arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j]
        }
    }
}

int main(){
    return 0;
}