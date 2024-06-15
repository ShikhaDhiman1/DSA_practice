#include <iostream>
#include <stack>
using namespace std;

// approach 1==========================================
void insertSorted(stack<int> *st, int temp){
    if((*st).empty() || temp >= (*st).top()){
        (*st).push(temp);
        return;
    }

    int temp2 = (*st).top();
    (*st).pop();
    insertSorted(st, temp);
    (*st).push(temp2);
}
void sort2(stack<int> &st){
    if(st.size() <= 1) return;

    int temp = st.top();
    st.pop();
    sort2(st);

    insertSorted(&st, temp);
}

// approach 2=========================================
void sort(stack<int> &st){
    if(st.size() <= 1) return;

    int temp = st.top();
    st.pop();
    sort(st);

    if(temp >= st.top()){
        st.push(temp);
    }
    else{
        int temp2 = st.top();
        st.pop();
        st.push(temp);
        sort(st);
        st.push(temp2);
    }
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(2);
    st.push(0);
    st.push(4);
    st.push(1);

    sort(st);
    // sort2(st);
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";
    return 0;
}