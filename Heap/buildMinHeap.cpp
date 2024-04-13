#include <iostream>
#include <vector>
using namespace std;

//------------------------------------------------------------------------------------------------
    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-FOR 0-based INDEXING->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// void minHeapify(int *arr, int size, int i){
//     int smallest = i;
//     // For 1 based indexing:
//     // int left = 2*i;
//     // int right = 2*i + 1;

//     //For 0 based indexing:
//     int left = 2*i + 1;
//     int right = 2*i + 2;

//     if(left < size && arr[left] < arr[smallest]){
//         smallest = left;
//     }
//     if(right < size && arr[right] < arr[smallest]){
//         smallest = right;
//     }

//     if(smallest != i){
//         swap(arr[smallest], arr[i]);
//         minHeapify(arr, size, smallest);
//     }
//     return;
// }

// void buildMinHeap(int *arr, int size){
//     for(int i = size/2-1; i >= 0; i--){
//         minHeapify(arr, size, i);
//     }
//     return;
// }

// void heapsort(int* arr, int n){
//     int size = n-1;
//     while(size > 0){
//         swap(arr[0], arr[size]);
//         size--;
//         minHeapify(arr, size, 0);
//     }
//     return;
// }
//----------------------------------------------------------------------------------------------
    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-FOR 0-based INDEXING->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void minHeapify(int *arr, int size, int i){
    int smallest = i;
    // For 1 based indexing:
    int left = 2*i;
    int right = 2*i + 1;

    // //For 0 based indexing:
    // int left = 2*i + 1;
    // int right = 2*i + 2;

    if(left <= size && arr[left] < arr[smallest]){
        smallest = left;
    }
    if(right <= size && arr[right] < arr[smallest]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[smallest], arr[i]);
        minHeapify(arr, size, smallest);
    }
    return;
}

void buildMinHeap(int *arr, int size){
    for(int i = size/2; i >= 1; i--){
        minHeapify(arr, size, i);
    }
    return;
}

void heapsort(int* arr, int n){
    int size = n;
    while(size > 1){
        swap(arr[1], arr[size]);
        size--;
        minHeapify(arr, size, 1);
    }
    return;
}

int main(){

    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-FOR 0-based INDEXING->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    // int* arr = new int[8]{19, 10, 15, 7, 4, 3, 2, 1};
    
    // cout<<"\nArray is : \n";
    // for(int i = 0; i < 8; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    // buildMinHeap(arr, 8);

    // cout<<"\nMin-Heap is : \n";
    // for(int i = 0; i < 8; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    // cout<<"\nArray is : \n";
    // heapsort(arr, 8);
    // for(int i = 0; i < 8; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-FOR 1-based INDEXING->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    int* arr = new int[9]{-1, 19, 10, 15, 7, 4, 3, 2, 1};
    
    cout<<"\nArray is : \n";
    int n = 8;
    for(int i = 1; i <= n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    buildMinHeap(arr, n);

    cout<<"\nMin-Heap is : \n";
    for(int i = 1; i <= 8; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"\nArray is : \n";
    heapsort(arr, 8);
    for(int i = 1; i <= 8; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}