#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

string twoSum(vector<int> &book, int target){
    //BRUTE force Approach:--------------------->>>>>>>>>>>>>>>>
    // T.C. = O(n^2)
    // S.C. = O(1)
    // for(int i = 0; i < book.size(); i++){
    //     for(int j  = i + 1; j < book.size(); j++){
    //         if(book[i] + book[j] == target){
    //             return "YES";
    //         }
    //     }
    // }
    // return "NO";

    // BETTER approach:--------------->>>>>>>>>>(Not correct when indexes are to be returned)
    // T.C. = O(nlogn) + O(n);
    // S.C  = O(1) {or O(n) for sorting array}
    // int left = 0;
    // int right = book.size() - 1;

    // sort(book.begin(), book.end());

    // while(left < right){
    //     int x = book[left] + book[right];

    //     if(x == target) return "YES";
    //     else if(x < target){
    //         left++;
    //     }
    //     else right--;

    //     return "NO";
    // }

    // Optimal approach
    // T.C. = O(n)
    // S.C. = O(n)
    unordered_map <int, int> mp;
    for(int i = 0; i < book.size(); i++){
        if(mp[target - book[i]] != 0){
            return "YES";
        }
        mp[book[i]]++;
    }
    return "NO";
}

vector<int> twoSum2(vector<int> &arr, int target){
    // BRUTE force :-------------->>>>>>>>>>>>>>>>>>>
    // T.C. = O(n^2)
    // S.C. = O(1)
    // for(int i = 0; i < arr.size(); i++){
    //     for(int j = i + 1; j < arr.size(); j++){
    //         if(arr[i] + arr[j] == target){
    //             return {i, j};
    //         }
    //     }
    // }
    // return {-1, -1};

    // Optimal Approach:----------->>>>>>>>>>>>>>>
    //T.C. = O(n);
    //S.C. = O(n) {used to store map}
    unordered_map<int, int> mp;

    for(int i = 0; i < arr.size(); i++){
        if(mp.find(target - arr[i]) != mp.end()){
            return {mp[target - arr[i]], i};
        }
        mp[arr[i]] = i;
    }
    return {-1, -1};
}

int main(){
    vector<int> book = {4, 1, 2, 3, 1};
    cout<<twoSum(book, 5)<<"\n";
    vector<int> indexes = twoSum2(book, 5);
    for(auto x : indexes){
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}