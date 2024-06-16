#include <iostream>
#include <set>
using namespace std;

void uniqueSubsets(int i, string str, string sub, set<string> &s){
    if(i == str.length()){
        s.insert(sub);
        return;
    }

    // sub[i] = str[i];
    uniqueSubsets(i + 1, str, sub + str[i], s);
    // sub.pop_back();
    uniqueSubsets(i + 1, str, sub, s);
}
string betterString(string str1, string str2){
    set<string> s1;
    uniqueSubsets(0, str1, "", s1);

    set<string> s2;
    uniqueSubsets(0, str2, "", s2);
    return s1.size() >= s2.size() ? str1 : str2;
}
int main(){
    string str1 = "gfg";
    string str2 = "gdc";

    cout<<betterString(str1, str2)<<"\n";
    return 0;
}