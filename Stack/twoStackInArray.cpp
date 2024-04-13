#include <iostream>
using namespace std;

#define n 10

class stack{
    private:
        int* arr;
        int top1;
        int top2;
    public:
        stack(){
            arr = new int[n];
            top1 = -1;
            top2 = n;
        }

        void push(int x1, int x2);
        void push1(int x1);
        void push2(int x2);
        void pop();
        void pop1();
        void pop2();
        bool empty();
        void top();
        int Top1();
        int Top2();
};

void stack::push(int x1, int x2){
    if(top1 == top2){
        cout<<"\nStack Overflow!\n";
        return;
    }
    top1++;
    top2--;
    arr[top1] = x1;
    arr[top2] = x2;
    // cout<<top1<<" "<<top2<<endl;
    return;
}

void stack::push2(int x2){
    top2--;
    if(top1 == top2){
        cout<<"\nStack Overflow!\n";
        return;
    }
    arr[top2] = x2;
    // cout<<"top2: "<<top2<<endl;
    return;
}

void stack::push1(int x1){
    top1++;
    if(top1 == top2){
        cout<<"\nStack Overflow!\n";
        return;
    }
    arr[top1] = x1;
    // cout<<"top1: "<<top1<<endl;
    return;
}

void stack::pop(){
    if(top1 == -1 || top2 == n){
        cout<<"\nStack Underflow!\n";
        return;
    }
    // pop1();
    // pop2();
    cout<<"\nPopped element of\n-> stack1: "<<arr[top1]<<"\n-> stack2: "<<arr[top2]<<endl;
    top1--;
    top2++;
    return;
}

void stack::pop1(){
    if(top1 == -1){
        cout<<"\nStack Underflow!\n";
        return;
    }
    top1--;
    return;
}

void stack::pop2(){
    if(top2 == n){
        cout<<"\nStack Underflow!\n";
        return;
    }
    top2++;
    return;
}

void stack::top(){
    if(top1 == -1 && top2 == n){
        cout<<"\nNo element present!\n";
        return;
    }
    cout<<"\nTop element of\n-> stack1 is: "<<arr[top1]<<"\n-> stack2 is: "<<arr[top2]<<endl;
    return;
}

int stack::Top1(){
    if(top1 == -1){
        cout<<"\nNo element present!\n";
        return -1;
    }
    return arr[top1];
}

int stack::Top2(){
    if(top2 == n){
        cout<<"\nNo element present!";
        return -1;
    }
    return arr[top2];
}

int main(){
    stack s;
    s.push(1, 10);
    s.push(2, 9);
    s.push(3, 8);
    s.push(4, 7);
    s.push1(8);
    s.push1(18);
    s.push1(28);

    s.pop();

    s.top(); 

    s.pop();

    s.push(5, 6);
    s.top();

    s.pop1();
    s.pop1();

    cout<<"\nTop of stack1: "<<s.Top1();
    cout<<"\nTop of stack2: "<<s.Top2()<<endl;

    s.pop2();
    s.pop2();
    s.pop();
    s.pop();
    

    cout<<"\nTop of stack1: "<<s.Top1();
    cout<<"\nTop of stack2: "<<s.Top2();

    cout<<endl<<endl;
    return 0;
}