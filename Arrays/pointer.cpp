#include <iostream>
using namespace std;

struct employee{
    int id;
    int salary;
    string name;
    void display(){
        cout<<id<<" "<<salary<<" "<<name<<endl;
        return;
    }
};
typedef struct employee1{
    int id;
    int salary;
    string name;
    void display(){
        cout<<id<<" "<<salary<<" "<<name<<endl;
        return;
    }
}ep;

void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    return;
}

// call by reference using pointer
// call by refernce using pointer reference
void swapPtr(int *a, int *b){
    cout<<"By-Pointer\n";
    // cout<<a<<" "<<b<<endl;
    int temp = *a;
    *a = *b;
    *b = temp;
    delete a;
    delete b;
    return;
}

// call by reference using C++ reference
//call by refernce using reference variable
void swapRefr(int &a, int &b){
    cout<<"By-Refernce\n";
    // cout<<a<<" "<<b<<endl;
    int temp = a;
    a = b;
    b = temp;
    return;
}

int main(){
    // int arr = [1, 2, 3, 4, 5];
    int arr[] = {1,2,3,4,5};
    int *p = arr;
    int n = sizeof(arr)/ sizeof(arr[0]);
    for(int i = 0; i < n; i++){
        cout<<(*arr + i)<<" ";
        cout<<*(arr + i)<<" ";
        cout<<(*p + i)<<" \n";
        // cout<<(*p)<<" ";
        // ptr++;
    }
    for( auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;

    employee e1;
    e1.id = 274;
    e1.name = "kdjkvbk";
    e1.salary = 734827979;
    e1.display();

    ep e2;
    e2.id = 274;
    e2.name = "kdjkvbk";
    e2.salary = 734827979;
    e2.display();

    int a, b;
    cin>>a>>b;
    int *x = &a;
    int *y = &b;
    swap(x, y); // incorrect
    cout<<a<<" "<<b<<endl;
    swapPtr(&a, &b);
    cout<<a<<" "<<b<<endl;
    swapRefr(a, b);
    cout<<a<<" "<<b<<endl;

    int num = 10;
    int *ptr = &num;
    int **qtr = &ptr;

    cout<<"qtr = "<<qtr<<", &ptr = "<<&ptr<<endl;
    cout<<"*qtr = "<<*qtr<<",  ptr = "<<ptr<<endl;
    cout<<"**qtr = "<<**qtr<<",  *ptr = "<<*ptr<<endl;
    return 0; //signifies successful termination of main function
}