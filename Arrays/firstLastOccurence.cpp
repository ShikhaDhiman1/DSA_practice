#include <iostream>
using namespace std;

static int count = 0;

int firstOcc(int* arr, int n, int key){
    int start = 0;
    int end = n-1;
    int ans = -1;
    int max;
    while( start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] == key){
            ans = mid;
            end = mid - 1;
            count++;
        }
        else if(key < arr[mid]){
            end = mid - 1;
        }
        else{
            start = mid + 1;
            max  = start;
        }
    }
    cout<<"peak: "<<max<<endl;
    // if(start > end) return -1;
    return ans;
}

int lastOcc(int * arr, int n, int key){
    int start = 0; 
    int end = n-1;
    int ans = -1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(key == arr[mid]){
            ans = mid;
            start = mid + 1;
            count++;
        }
        else if( key < arr[mid]){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n, key;
    cout<<"Enter the size of array: ";
    cin>>n;
    int* arr = new int[n];
    cout<<"Enter the array: ";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the key: ";
    cin>>key;
    cout<<"First Occurence: "<<firstOcc(arr, n, key)<<"  |  Last Occurence: "<<lastOcc(arr, n, key)<<endl;
    cout<<"Number of occurences of "<<key<<" is/are: "<<count<<endl<<endl;
    // OR ---> no. of occ.= (lastOcc - firstOcc) + 1
    cout<<"Number of occurences : "<<((lastOcc(arr, n , key) - firstOcc(arr, n, key)) +1)<<endl;
    return 0;
}