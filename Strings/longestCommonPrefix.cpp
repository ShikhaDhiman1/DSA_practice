#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs){
    string temp = strs[0];
    string ans = "";
    for(int i = 1; i < strs.size(); i++){
        string str = strs[i];
        for(int i = 0; i < min(temp.size(), str.size()); i++){
            if(str[i] == temp[i]){
                ans += temp[i];
            }
            else break;
        }
        temp = ans;
        ans = "";
    }
    return temp;
}

int main(){
    vector<string> strs = {"flower", "float", "flood"};
    strs = {"car", "coat"};
    cout<<longestCommonPrefix(strs)<<"\n";
    return 0;
}