#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s){
    int n = s.length();
    if(n % 2 != 0) return false;

    stack<char> st;

    for(int i = 0; i < n; i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }
        else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
            if(!st.empty()){
                if(st.top() == '(' && s[i] == ')'){
                    st.pop();
                }
                else if(st.top() == '{' && s[i] == '}'){
                    st.pop();
                }
                else if(st.top() == '[' && s[i] == ']'){
                    st.pop();
                }
                else return false;
            }
            else return false;
        }
    }
    if(st.empty()) return true;
    else return false;
}

int main(){
    string s = "[([]])";
    cout<<isValid(s)<<endl;
    return 0;
}