#include <iostream>
using namespace std;

class heap{
    public:
        int *arr = new int[100];
        int size;

        heap(){
            arr[0] = -1;
            size = 0;
        }

        void insert(int val){
            size++;
            int index = size;
            arr[index] = val;

            while(index > 1){
                int parent = index/2;

                if(arr[parent] < arr[index]) {
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else return;
            }
            return;
        }

        void deleteRoot(){
            arr[1] = arr[size];
            size--;
            int i = 1;
            while(i < size){
                int left = 2*i;
                int right = 2*i + 1;

                if(left < size && arr[left] > arr[i]){
                    swap(arr[left], arr[i]);
                    i = left;
                }

                else if(right < size && arr[right] > arr[i]){
                    swap(arr[right], arr[i]);
                    i = right;
                }
                else return;
            }
            return;
        }


        void print(){
            for(int i = 1; i <= size; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            return;
        }
};

// void heapify(int *arr, int size, int i){
//     int left = 2*i;
//     int right = 2*i + 1;

//     while(i <= size){
//         int large = 0;
//         if(left <= size && right <= size){
//             if(arr[left] < arr[right]){
//                 large = right;
//             }
//             else large = left;

//             swap(arr[i], arr[large]);
//             i = large;
//         }
//         else return;
//     }
//     return;
// }

// void heapify(int *arr, int size, int i){
//     int left = 2*i;
//     int right = 2*i + 1;

//     int large = 0;
//     if(left <= size && right <= size){
//         if(arr[left] < arr[right]){
//             large = right;
//         }
//         else large = left;

//         swap(arr[i], arr[large]);
//         i = large;
//     }
//     else return;
// }

void maxHeapify(int* arr, int size, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= size && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= size && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        maxHeapify(arr, size, largest);
    }
    return;
}


void minHeapify(int* arr, int size, int i){
    int smallest = i;
    int left = 2*i;
    int right = 2*i + 1;

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

int main(){

    heap h1;
    h1.insert(3);
    h1.insert(13);
    h1.insert(1);
    h1.insert(10);
    h1.insert(9);
    h1.insert(19);
    h1.insert(44);

    h1.print();
    cout<<endl;

    h1.deleteRoot();

    h1.print();
    cout<<endl;

    h1.deleteRoot();

    h1.print();
    cout<<endl;

    for(int i = 1; i <= h1.size/2; i++){
       maxHeapify(h1.arr, h1.size, i);
    }

    h1.print();
    cout<<endl;

    int a[7] ={-1, 4, 7, 10, 9, 12, 1};
    cout<<"\nArray is : \n";
    for(int i = 1; i <=6; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    cout<<"\nMin-Heapify : \n";
    for(int i = 3; i >= 1; i--){
       maxHeapify(a, 6, i);
    }
    for(int i = 1; i <=6; i++){
       cout<<a[i]<<" ";
    }
    cout<<endl;

    cout<<"\nMin-Heapify : \n";
    for(int i = 3; i >= 1; i--){
        minHeapify(a, 6, i);
    }
    for(int i = 1; i <=6; i++){
       cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}