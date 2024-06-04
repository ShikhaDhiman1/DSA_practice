#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

string reverseWords(string s) {
    string res = "";
    stack<string> st;
    string word = "";
    
    for(int i = 0; i< s.size(); i++){
        if(s[i] == ' ' && (!word.empty())){
            st.push(word);
            word = "";
        }
        else{
            word += s[i];
        }
    }
    if(!word.empty()) st.push(word);

    cout<<st.size()<<"\n";
    
    while(st.size() != 1){
        string x = st.top();
        res += (x + " ");
        st.pop();
    }
    res += st.top();
    return res;
}

string reverseWords2(string s){
    string res = "";
    string word = "";

    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ' && !(word.empty())){
            if(res != ""){
                res = word + " " + res;
            }
            else{
                res = word;
            }
            word = "";
        }
        else if(s[i] != ' '){
            word += s[i];
        }
    }

    if(!(word.empty())){
        if(res != ""){
            res = word + " " + res;
        }
        else{
            res = word;
        }
    }
    return res;
}

int main(){
    string input = " hello world ";
    cout<<"'"<<reverseWords(input)<<"'\n";
    cout<<"'"<<reverseWords2(input)<<"'\n";
    return 0;
}