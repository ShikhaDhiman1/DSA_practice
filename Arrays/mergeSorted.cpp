#include<iostream>
#include<vector>
#include <map>
using namespace std;

vector <int> sortedArray(vector <int> a, vector <int> b) {
    // Write your code here
    vector<int> res;
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

    map<int, int> mpA;
    map<int, int>mpB;

    for(int i = 0; i < a.size(); i++){
        mpA[a[i]]++;
    }
    for(int j = 0; j < b.size(); j++){
        mpB[b[j]]++;
    }
   for(auto it : mapA){
       if(mpB[it.first] != 0) mpB[it.first] = 0;
       res.push_back(it.first);
   }
   for(auto it : mpB){
       if(mpB[it.first] != 0) res.push_back(it.first);
   }
   sort(res.begin(), res.end());
    return res;
}
