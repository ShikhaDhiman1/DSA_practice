#include <iostream>
using namespace std;

#define len 100

class node{
    public:
        node* next;
        int data;
        node(int val){
            next = NULL;
            data = val;
        }
};

int size(node* &head){
    node* temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

class stack {
    private:
        node* top;
        // node* n;
    public:
    stack(){
        top = NULL;
    }
        void push(int x);
        void pop();
        bool empty();
        int Top();
};

void stack::push(int x){
    int l = size(top);
    if(l == len-1){
        cout<<"\nStack Overflow!\n";
        return;
    }
    node* n1 = new node(x);
    n1->next = top;
    cout<<x<<" ";
    top = n1;
    return;
}

void stack::pop(){
    if(!top){
        cout<<"\nStack Underflow!\n";
        return;
    }
    node* temp = top;
    cout<<"\nPopped element is : "<<top->data<<endl;
    top = top->next;
    delete temp;
    return;
}

int stack::Top(){
    if(!top){
        cout<<"\nStack is Empty!\n";
        return -1;
    }
    return top->data;
}

bool stack::empty(){
    return (!top);
}

int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    cout<<endl;
    cout<<"\nTop element in the stack is : "<<s.Top()<<endl;
    
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    cout<<"\nTop element in the stack is : "<<s.Top()<<endl;

    if(s.empty()) cout<<"\nStack is Empty...\n";
    else{
        cout<<"\nStack is Not Empty...\n";
    }

    s.pop();
    s.pop();
    s.pop();

    if(s.empty()) cout<<"\nStack is Empty...\n";
    else{
        cout<<"\nStack is Not Empty...\n";
    }

    cout<<endl;
    return 0;
}