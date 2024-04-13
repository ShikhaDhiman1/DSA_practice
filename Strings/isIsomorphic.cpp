#include <iostream>
#include <set>
#include <map>
using namespace std;

bool tellIsIso(string s1, string s2){
    int l1 = s1.length();
    // int l2 = s2.length;
    map< char, set<char> > dict;
    for(int i = 0; i < l1; i++){
        dict[s1[i]].insert(s2[i]);
        cout<<"size : "<<dict[s1[i]].size()<<endl;
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

int main(){
    string s = "egggf";
    string t = "addii";
    cout<<isIsomorphic(s, t)<<endl;
    return 0;
}