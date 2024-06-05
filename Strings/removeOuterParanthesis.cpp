#include <iostream>
#include <string>
using namespace std;

// (()())(())()
string removeParanthesis(string s){
    int count = 0;
    string ans = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            if(count > 0){
                ans += s[i];
            }
            count++;
        }
        else if(s[i] == ')'){
            if(count > 1){
                ans += s[i];
            }
            count--;
        }
    }
    return ans;
}

int main(){
    string s = "(()())((()))()";
    cout<<removeParanthesis(s)<<"\n";
    return 0;
}