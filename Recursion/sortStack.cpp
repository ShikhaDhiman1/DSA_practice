#include <iostream>
#include <stack>
using namespace std;

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
void sort(stack<int> &st){
    if(st.size() <= 1) return;

    int temp = st.top();
    st.pop();
    sort(st);
    st.push(temp);

    insertSorted(&st, temp);
}

void sort(stack<int> &st){
    if(st.size() <= 1) return;

    int temp = st.top();
    st.pop();
    sort(st);
    st.push(temp);

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
    return 0;
}