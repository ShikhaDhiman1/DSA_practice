#include <iostream>
using namespace std;

#define n 10

class stack{
    private:
        int *arr;
        int top;
    public:
        stack(){
            arr = new int[n];
            top = -1;
        }
        void push(int x);
        void pop();
        int Top();
        bool isEmpty();
};

void stack::push(int x){
    if(top == n-1){
        cout<<"\nStack Overflow!!!\nCannot add more elements to the stack!\n";
        return;
    }
    top++;
    arr[top] = x;
    return;
}

void stack::pop(){
    if(top==-1){
        cout<<"Stack Underflow!!!\nNo more elements to pop\n";
        return;
    }
    cout<<"\nElement popped is : "<<arr[top]<<endl;
    top--;
    return;
}

bool stack::isEmpty(){
    return (top == -1);
}

int stack::Top(){
    if(isEmpty()){ // This is nesting of member functions.
        cout<<"\nOops! Stack is Empty!\n";
        return -1;
    }
    return arr[top];
}

int main(){
    stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.push(7);
    s1.push(8);
    s1.push(9);
    s1.push(10);
    s1.push(11);
    s1.push(6);

    cout<<"\nTop element is : "<<s1.Top()<<endl;

    s1.pop();
    s1.pop();
    s1.pop();
    cout<<"\nTop element is : "<<s1.Top()<<endl;
    s1.pop();
    if(s1.isEmpty()){
        cout<<"\nStack is empty...\n";
    }
    else{
        cout<<"\nStack is not empty...\n";
    }
    s1.pop();
    cout<<"\nTop element is : "<<s1.Top()<<endl;
    s1.pop();
    s1.pop();
    if(s1.isEmpty()){
        cout<<"\nStack is empty...\n";
    }
    else{
        cout<<"\nStack is not empty...\n";
    }
    s1.pop();
    s1.pop();
    s1.pop();
    if(s1.isEmpty()){
        cout<<"\nStack is empty...\n";
    }
    else{
        cout<<"\nStack is not empty...\n";
    }
    cout<<endl;
    return 0;
}