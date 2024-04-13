#include <iostream>
#include <set>
#include <bits/stdc++.h>
using namespace std;

int main(){
    set <int> s;
    s.insert(2);
    s.insert(9);
    s.insert(10);
    s.insert(21);
    s.insert(12);
    s.insert(2);

    for(auto i: s){
        cout<<i<<" ";
    }
    cout<<endl;

    vector <int> v;
    
    list<int> l;
    stack <int> st;
    st.push(2);
    st.push(12);
    st.push(21);
    st.push(32);
    st.push(9);
    // iterator not supported in stack:
    // stack <int> :: iterator it;
    // for(auto i: st){
    //     cout<<i<<" ";
    // }

    queue <int> q;
    q.push(2);
    q.push(12);
    q.push(21);
    q.push(32);
    q.push(9);
    // Iterator not suppoorted in queue;

    deque <int> dq;
    dq.push_back(2);
    dq.push_back(12);
    dq.push_back(21);
    dq.push_front(32);
    dq.push_front(9);
    deque <int>:: iterator it;
    for(it = dq.begin(); it != dq.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    for(auto i:dq){
        cout<<i<<" ";
    }
    cout<<endl;

    priority_queue<int> pq;

    pair<int, vector<int>> pr;
    pair <int, int> pr1;

    return 0;
}