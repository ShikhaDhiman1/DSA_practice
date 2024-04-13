// Operator Overloading:-> Polymorphism at compile time

#include <iostream>
using namespace std;

class complex{
    public:
    double real;
    double imag;
    complex(){}
    complex(double r, double i){
        real = r;
        imag = i;
    }

    complex operator + (complex &c){
        complex c2;
        c2.real = real + c.real;
        c2.imag = imag + c.imag;
        return c2;
    }

    void display(){
        cout<<"Complex Number is : "<<real<<" + i("<<imag<<")"<<endl;
        return;
    }
};

int main(){
    complex c1(3, 1.9);
    complex c2(2.6, 9);
    c1.display();
    c2.display();
    complex c3 = c1 + c2;
    cout<<"Resulting complex number is : \n";
    c3.display();
    return 0;
}