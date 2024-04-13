#include <iostream>
using namespace std;

// Types of Mcros : 
// 1. Object - like Macros
// 2. Chain Macros
// 3. Multi-line Macros
// 4. Function - like Macros

#define pi 3.14                      // Object-like Macro
#define area_circle(r)(pi * r * r)   // Chain macro + a funtion-like macro
#define arr1 1,\
             2,\
             3,\
             4,\
             5   // Multi-line macro (can be done only by using a backslash only and using multiple lines only )
#define area_rect(l, b)(l * b)       // Function-like macro
#define max(a, b)(a > b ? a : b)

int main(){
    int arr[]  = {arr1};
    cout<<"\nArray declared using a multi - line macro is : \n";
    for(int i = 0; i < 5; i ++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"\nArea of circle with radius = 5 using a chain macro and a function-like macro is : \n";
    cout<<area_circle(5)<<endl;

    cout<<"\nArea of a rectangle with l = 7.5 and b = 4 using a function-like macro is :\n";
    cout<<area_rect(7.5, 4)<<endl;

    cout<<"\nMaximum of two numbers 5 and 9 using a function-like macro is :\n";
    cout<<max(5, 9)<<endl<<endl;

    return 0;
}