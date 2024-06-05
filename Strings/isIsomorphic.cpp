#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool tellIsIso(string s1, string s2){
    int l1 = s1.length();
    map< char, set<char> > dict;
    for(int i = 0; i < l1; i++){
        dict[s1[i]].insert(s2[i]);
        if(dict[s1[i]].size() > 1) return false;
    }
    return true;
}
bool isIsomorphic(string s, string t) {
    if(s.length() != t.length()) return false;
    bool b1 = tellIsIso(s, t);
    bool b2 = tellIsIso(t, s);

    return (b1 && b2);
}

bool tellIsomorphic(string s, string t){
    if(s.size() != t.size()) return false;
    unordered_map<char, int> mp;

    // for(int i = 0; i < s.size(); i++){
    //     if(mp.find(s[i]) == mp.end()){
    //         mp[s[i]] = t[i];
    //     }
    //     else{
    //         if(mp[s[i]] != t[i]) return false;
    //     }
    // }
    // return true;
    // OR++==========================================
    for(int i = 0; i < s.size(); i++){
        if(mp.find(s[i]) == mp.end()){
            mp[s[i]] = t[i]; 
            char oldCh = t[i], newCh = s[i];
            replace(t.begin(), t.end(), oldCh, newCh);
        }
    }
    if(t == s) return true;
    return false;
}

bool isIsomorphic2(string s, string t){
    return (tellIsomorphic(s, t) && tellIsomorphic(t, s));
}

int main(){
    string s = "egggf";
    string t = "adddi";
    cout<<isIsomorphic(s, t)<<endl;
    cout<<isIsomorphic2(s, t)<<"\n";
    string x = "adddii";
    replace(x.begin(), x.end(), 'd', 'g');
    cout<<x<<"\n";
    return 0;
}