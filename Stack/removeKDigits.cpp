#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.*/

string removeKdigits(string num, int k){
    int n = num.size();
    if(n == k) return "0";

    stack<char> st;
    for(auto ch : num){
        while(!st.empty() && st.top() > ch && k){
            st.pop();
            k--;
        }
        if(!st.empty() || ch != '0'){ 
            st.push(ch);
        }
    }

    while(!st.empty() && k--){
        st.pop();
    }
    if(st.empty()) return "0";

    while(!st.empty()){
        num[n - 1] = st.top();
        st.pop();
        n--;
    }

    return num.substr(n);
}

int main(){
    string  num = "10200";
    int k = 1;
    cout<<removeKdigits(num, k)<<"\n";
    return 0;
}