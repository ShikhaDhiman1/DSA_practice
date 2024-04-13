#include <iostream>
#include <stack>
using namespace std;

void reverse(string s){
    stack <string> st;
    for(int i = 0; i < s.length(); i++){
        string s2 = "";
        while(s[i] != ' ' && i<s.length()){
            s2 += s[i];
            i++;
        }
        st.push(s2);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return;
}

int main(){
    string sentence = "Hey, How are you doing?";
    cout<<"\nOriginal sentence is : \n"<<sentence<<endl;
    cout<<"\nReversed sentence is : \n";
    reverse(sentence);
    cout<<endl;
    string s;
    getline(cin, s);
    cout<<"\nOriginal sentence is : \n"<<s<<endl;
    cout<<"\nReversed sentence is : \n";
    reverse(s);
    cout<<endl;
    // cout<<"\nOriginal sentence is : \n"<<sentence<<endl;
    // cout<<"\nReversed sentence is : \n";
    // reverse(sentence);
    // cout<<endl;
    return 0;
}