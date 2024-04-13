// Function Overloading:-> Polymorphism at compile time.

#include <iostream>
using namespace std;

class A{
    public:
    void func(){
        cout<<"This is function 'func' with no arguments.\n";
        return;
    }
    void func(int a){
        cout<<"This is function 'func' with an integer argument with value : "<<a<<endl;
        return;
    }
    void func(int a, string b){
        cout<<"This is function 'func' with two arguments with value: "<<a<<" and "<<b<<endl;
    }
};

int main(){
    A a;
    a.func();
    a.func(3);
    a.func(7, "Hey");
    return 0;
}