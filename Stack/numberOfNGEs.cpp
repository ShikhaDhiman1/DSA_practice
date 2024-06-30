#include <iostream>
#include <vector>
using namespace std;

vector<int> count_NGE(vector<int> &arr, vector<int> &queries){
    vector<int> ans;

    for(auto ind : queries){
        int count = 0;
        for(int i = ind + 1; i < arr.size(); i++){
            if(arr[i] > arr[ind]) count++;
        }
        ans.push_back(count);
    }

    return ans;
}

int main(){
    vector<int> arr = {3, 4, 2, 7, 5, 8, 10, 6};
    vector<int> queries = {0, 5};
    
    vector<int> ans = count_NGE(arr, queries);
    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}