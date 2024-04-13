// Function Overriding:-> Polymorphism at run time

#include <iostream>
using namespace std;

class base{
    public:
        virtual void display(){
            cout<<"This is BASE class's 'display' function.\n";
            return;
        }
};

class derived: public base{
    public:
        void display(){
            cout<<"This is DERIVED class's 'display function.\n";
            return;
        }
};

int main(){
    base *bptr;
    derived d;
    bptr = &d;
    bptr -> display();
    cout<<endl;

    base* b1 = new derived();
    b1->display();
    cout<<endl;

    base b;
    b.display();
    cout<<endl;

    derived d1;
    d1.display();
    cout<<endl;
    return 0;
    // https://youtu.be/E16WhXcIghM
}