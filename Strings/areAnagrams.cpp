#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool areAnagram(string s, string t){
    if(s.size() != t.size()) return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if(s == t) return true;
    return false;
}

bool areAnagram2(string s, string t){
    if(s.size() != t.size()) return false;

    unordered_map<char, int> mp;

    for(auto ch : s){
        mp[ch]++;
    }

    for(auto ch : t){
        if(mp.find(ch) == mp.end() || mp[ch] == 0) return false;
        mp[ch]--;
    }

    for(auto x : mp){
        if(x.second != 0) return false;
    }

    return true;
}

int main(){
    string s = "anagram";
    string t = "nagaram";
    cout<<areAnagram(s, t)<<"\n";
    cout<<areAnagram2(s, t)<<"\n";
    return 0;
}