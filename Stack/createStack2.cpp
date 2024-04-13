#include <iostream>
using namespace std;

const int max_len = 10;

class stack{
    private:
    int *arr;
    int top = -1;
    public:
    void push(int x);
    void pop();
    int returnTop();
    bool isEmpty();
};

void stack::push(int x){
    if(top >= max_len-1){
        cout<<"\nStack Overflow!!!\n";
        return;
    }
    top++;
    arr[top] = x;
    return;
}

void stack::pop(){
    // delete arr[top];
    if(top < 0){
        cout<<"\nStack Underflow!!!\n";
        return;
    }
    cout<<arr[top]<<endl;
    top--;
    return;
}

int stack::returnTop(){
    return arr[top];
}

bool stack::isEmpty(){
    if(top > -1) return false;
    else return true;
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

    cout<<"\nTop element is : "<<s1.returnTop()<<endl;

    s1.pop();
    s1.pop();
    s1.pop();
    cout<<"\nTop element is : "<<s1.returnTop()<<endl;
    s1.pop();
    if(s1.isEmpty()){
        cout<<"\nStack is empty\n";
    }
    else{
        cout<<"\nStack is not empty\n";
    }
    s1.pop();
    cout<<"\nTop element is : "<<s1.returnTop()<<endl;
    s1.pop();
    s1.pop();
    if(s1.isEmpty()){
        cout<<"\nStack is empty\n";
    }
    else{
        cout<<"\nStack is not empty\n";
    }
    cout<<endl;
    return 0;
}