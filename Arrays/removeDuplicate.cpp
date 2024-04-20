#include <iostream>
#include <vector>
#include <set>
using namespace std;

int removeDuplicates(vector<int> &arr, int n) {
	int ind = 0;
	int i = 0;
	while(i < n-1){
		while(arr[i] == arr[i+1]){
			i++;
		}
		if(arr[i] != arr[i + 1] && i+1 < n){
			cout<<i<<":"<<arr[i]<<", "<<i+1<<":"<<arr[i+1]<<"\n";
			ind++;
			arr[ind] = arr[i+1];
			i++;
		}
	}
	return (ind + 1);
}

// OPTIMAL approach:----------------------->>>>>>>>>>>>>>>>>>>>
// int removeDuplicates2(vector<int> &arr, int n){
// 	int i = 0;
// 	for(int j = 1; j < n; j++){
// 		if(arr[i] != arr[j]){
// 			i++;
// 			arr[i] = arr[j];
// 		}
// 	}
// 	return (i+1);
// }



// BRUTE FORCE approach:-------------------->>>>>>>>>>>>>>>>>>>>
// int removeDuplicates3(vector<int> &arr, int n){
// 	set<int> st;
// 	for(int i = 0; i < n; i++){
// 		st.insert(arr[i]);
// 	}
// 	int j = 0;
// 	for(auto x : st){
// 		arr[j] = x;
// 		j++;
// 	}

// 	return j;
// }


int main(){
    vector<int> arr = {1,1,2,2,2,2,2,3,3,3,4,4};
	// arr = {1, 1, 2, 3, 3, 4, 5, 5, 5};
	// arr = {1,3,3,3,4,5};

    int x = removeDuplicates(arr, arr.size());

	cout<<x<<"\n";

    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}