#include <iostream>
#include <list>
using namespace std;

#define len 10

class stack{
    private:
        list <int> lst;
        int top;
    public:
        stack(){
            top = -1;
            
        }
        void push(int x);
        void pop();
        int Top();
        bool empty();
        void display();
};

void stack::push(int x){
    if(top == len-1){
        cout<<"\nStack Overflow!\n";
        return;
    }
    lst.push_back(x);
    top++;
    return;
}

void stack::pop(){
    if(top == -1){
        cout<<"\nStack Underflow!\n";
        return;
    }
    cout<<"\nElement Popped is : "<<lst.back()<<endl;
    top--;
    lst.pop_back();
    return;
}

int stack::Top(){
    if(top == -1){
        cout<<"\nNo Elements present!\n";
        return -1;
    }
    return lst.back();
}

bool stack::empty(){
    // if(lst.size() == 0) return true;
    // else return false;

    // return (lst.size() == 0);
    return (lst.empty());
}

void stack::display(){
    if(empty()) {
        cout<<"\nNo Elements present!\n";
        return;
    }
    cout<<"\nElements in the stack are: \n";
    list<int>::iterator it;
    for( it = lst.begin(); it != lst.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    return;
}

int main(){
    stack s;
    s.push(10);
    s.push(2);
    s.push(13);
    s.push(21);
    s.push(9);
    s.push(16);

    s.display();

    s.pop();
    s.pop();

    cout<<"\nTop element in the stack is : "<<s.Top()<<endl;

    s.display();

    if(s.empty()) cout<<"\nStack is Empty...\n";
    else{
        cout<<"\nStack is Not Empty...";
        s.display();
    }

    s.pop();
    s.pop();

    cout<<"\nTop element in the stack is : \n"<<s.Top()<<endl;

    s.pop();
    s.pop();
    s.pop();

    if(s.empty()) cout<<"\nStack is Empty...\n";
    else{
        cout<<"\nStack is Not Empty...\n";
        s.display();
    }

    cout<<endl;

    return 0;
}