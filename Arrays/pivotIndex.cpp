#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
    // int pivot;
    int size = nums.size();
    for(int i = 0; i < size; i++){
        int left = 0;
        int right = 0;
        cout<<"i : "<<i;
        // pivot = i;
        if(i == 0) left = 0;
        else{
            for(int j = 0; j < i; j++){
                left += nums[j];
            }
        }
        cout<<", left : "<<left;
        if(i == size-1) right = 0;
        else{
            for(int j = i+1; j < size; j++){
                right += nums[j];
            }
        }
        cout<<", right : "<<right<<endl;
        if(left == right) return i;
    }
    return -1;
}

int main(){
    vector <int> arr;
    arr.push_back(1);
    arr.push_back(7);
    arr.push_back(3);
    arr.push_back(6);
    arr.push_back(5);
    arr.push_back(6);

    cout<<pivotIndex(arr);
    return 0;
}