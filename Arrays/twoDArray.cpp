#include <iostream>
using namespace std;

int main(){
    int r, c;
    cout<<"Enter the number of rows: ";
    cin>>r;
    cout<<"Enter the number of columns: ";
    cin>>c;
    cout<<endl;

    int **arr = new int*[r];

    for(int i = 0; i < r; i++){
        arr[i] = new int[r];
    }
    
    cout<<"Enter the array : \n";
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"\nThe array is : \n";
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i = 0; i < r; i++){
        delete[] arr[i];  // deleting the int* stored in each row
    }

    delete[] arr; // deleting the array
    // delete[]* arr;
    cout<<endl;
    return 0;
}