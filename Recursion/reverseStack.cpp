#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int temp){
    if(st.empty()){
        st.push(temp);
        return;
    }

    int temp2 = st.top();
    st.pop();
    insertAtBottom(st, temp);
    st.push(temp2);
}

void reverseStack(stack<int> &st){
    if(st.size() <= 1) return;

    int temp = st.top();
    st.pop();
    reverseStack(st);

    insertAtBottom(st, temp);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverseStack(st);
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";

    return 0;
}