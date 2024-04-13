#include <bits/stdc++.h>
using namespace std;

#include <algorithm>
vector<int> getFrequencies(vector<int>& v) {
    map<int, int> hmap;
    vector<int> ans;

    for(auto x : v){
        hmap[x]++;
    }
    for(auto it : hmap){
        cout<<it.first<<" : "<<it.second<<endl;
    }
    cout<<endl;

    int maxfreq = 0;
    int minfreq = v.size();

    int maxele = 0;
    int minele = 0;

    for(auto x : hmap){
        if(x.second > maxfreq){
            maxele = x.first;
            maxfreq = x.second;
        }
        if(x.second < minfreq){
            minele = x.first;
            minfreq = x.second;
        }
    }
    
    ans.push_back(maxele);
    ans.push_back(minele);

    return ans;
}

int main(){
    vector<int> res;
    vector<int> v = {1, 2, 3, 1, 1, 4};
    res = getFrequencies(v);
    for(auto x : res){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}