#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <climits>
#include <queue>
using namespace std;

char maxFreqChar(map<char, int> &mp){
    int maxFreq = INT_MIN;
    char maxCh;

    for(auto x : mp){
        if(x.second > maxFreq){
            maxFreq = x.second;
            maxCh = x.first; 
        }
    }
    return maxCh;
}
string sortByFreq(string s){
    map<char, int> mp;
    string ans = "";

    for(auto ch : s){
        mp[ch]++;
    }

    for(int i = 0; i < mp.size(); i++){
        char maxCh = maxFreqChar(mp);
        for(int i = 0; i < mp[maxCh]; i++){
            ans += maxCh;
        }
        mp[maxCh] = 0;
    }
    return ans;
}

string sortByFreq2(string s){
    unordered_map<char, int> mp;
    priority_queue<pair<int, char>> pq;
    string ans = "";
    for(auto ch : s){
        mp[ch]++;
    }

    for(auto x : mp){
        pq.push({x.second, x.first});
    }

    while(!pq.empty()){
        int freq = pq.top().first;
        char ch = pq.top().second;
        pq.pop();
        for(int i = 0; i < freq; i++){
            ans += ch;
        }
    }
    return ans;
}

int main(){
    string s = "tree";
    cout<<sortByFreq(s)<<"\n";
    cout<<sortByFreq2(s)<<"\n";
    return 0;
}