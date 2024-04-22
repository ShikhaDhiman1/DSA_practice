#include<iostream>
#include<vector>
#include <algorithm>
#include <map>
using namespace std;

vector <int> mergeSortedArray(vector <int> a, vector <int> b) {
    // Write your code here
    vector<int> res;

    // Brute force 1:----------------------------->>>>>>>>>>>>>>>>>>>>>>>
    // for(int i = 0; i < a.size(); i++){
    //     if(find(b.begin(), b.end(), a[i]) != b.end()) continue;
    //     if(find(a.begin()+i+1, a.end(), a[i]) != a.end()) continue;
    //     res.push_back(a[i]);
    // }

    // for(int j = 0; j < b.size(); j++){
    //     if(find(b.begin()+j+1, b.end(), b[j]) != b.end()) continue;
    //     res.push_back(b[j]);
    // }

    // sort(res.begin(), res.end());


    //Brute Froce 2:----------------------------->>>>>>>>>>>>>>>>>>>>>>>>>
//     map<int, int> mpA;
//     map<int, int>mpB;

//     for(int i = 0; i < a.size(); i++){
//         mpA[a[i]]++;
//     }
//     for(int j = 0; j < b.size(); j++){
//         mpB[b[j]]++;
//     }
//    for(auto it : mpA){
//        if(mpB[it.first] != 0) mpB[it.first] = 0;
//        res.push_back(it.first);
//    }
//    for(auto it : mpB){
//        if(mpB[it.first] != 0) res.push_back(it.first);
//    }
//    sort(res.begin(), res.end());

    int n1 = a.size();
    int n2 = b.size();
    int i = 0, j = 0;

    while(i < n1 && j < n2){
        if(a[i] <= b[j]){
            if(res.empty() || res.back() != a[i]){
                res.push_back(a[i]);
            }
            i++;
        }
        else{
            if(res.empty() || res.back() != b[j]){
                res.push_back(b[j]);
            }
            j++;
        }
    }
    while(i < n1){
        if(res.empty() || res.back() != a[i]){
            res.push_back(a[i]);
        }
        i++;
    }
    while(j < n2){
        if(res.empty() || res.back() != b[j]){
            res.push_back(b[j]);
        }
        j++;
    }
    return res;
}

int main(){
    vector<int> a = {1, 2, 2, 3, 4, 5, 5, 6};
    vector<int> b = {1, 2, 3, 4, 4, 7, 7, 8};

    vector<int> ans = mergeSortedArray(a, b);

    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<"\n\n";
    return 0;
}
