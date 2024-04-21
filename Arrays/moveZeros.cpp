#include <iostream>
#include <vector>
using namespace std;

void moveZeros(int n, vector<int> &a) {
    // Write your code here.
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            vector<int>::iterator it = a.begin()+i;
            a.erase(it);
            a.push_back(0);
            n--;
            i--;
        }
    }
}

void moveZeroes(vector<int> &arr){
    int n = arr.size();

    int j = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }
    if(j == -1) return;

    int i = j+1;
    while(i < n){
        if(arr[i] != 0){
            swap(arr[i], arr[j]);
            j++;
        }
        i++;
    }

    // or:->
    // for(int i = j+1; i < n; i++){
    //     if(arr[i] != 0){
    //         swap(arr[i], arr[j]);
    //         j++;
    //     }
    // }
}

int main(){
    vector<int> v = {0, 0, 0, 1};
    v = {0, 1, 3, 2, 4, 0, 0, 9, 1, 0, 8, 0};
    // moveZeros(v.size(), v);

    moveZeroes(v);

    for(auto x : v){
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}