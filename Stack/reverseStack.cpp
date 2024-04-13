#include <iostream>
#include <stack>
using namespace std;

void reverse(stack<int> s){
    stack <int> s1;
    while(!s.empty()){
        s1.push(s.top());
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;
    return;
}

// reversing a stack using RECURSION:

void insertAtBottom(stack <int> &s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int topEle = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(topEle);
}

void reverseRecursive(stack <int> &s){
    if(s.empty()){
        return;
    }
    int x = s.top();
    s.pop();
    reverseRecursive(s);
    insertAtBottom(s, x);
    return;
}

// driver code:
int main(){
    stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverse(s);
    cout<<"\n--------------------\n";
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    stack <int> s1;
    s1.push(11);
    s1.push(21);
    s1.push(31);
    s1.push(41);
    s1.push(51);
    // while(!s1.empty()){
    //     cout<<s1.top()<<" ";
    //     s1.pop();
    // }
    reverseRecursive(s1);
    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;
    return 0;
}