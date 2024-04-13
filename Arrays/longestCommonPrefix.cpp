#include<iostream>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs){
    string cmnd = strs[0];
    for(auto i: strs){
        for(int j = 0; j < cmnd.length(); j++){
            if(i[j] != cmnd[j]){
              cmnd = cmnd.substr(0, j);
              cout<<cmnd<<endl;
              break;
            }
            if (cmnd=="") return cmnd;
        }
        if (cmnd=="") return cmnd;
    }
    return cmnd;
}

int main(){
    vector<string> strs;
    strs.push_back("ab");
    strs.push_back("a");
    // strs.push_back("racecar");
    cout<<longestCommonPrefix(strs)<<endl;
    return 0;
}