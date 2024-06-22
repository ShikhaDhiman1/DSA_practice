#include <iostream>
using namespace std;

int binaryToDecimal(string str){
    int num = 0, powTwo = 1;

    for(int i = str.length() - 1; i >= 0; i--){
        if(str[i] == '1'){
            num = num + powTwo;
        }
        powTwo *= 2;
    }

    return num;
}
int main(){
    string str = "1011";
    cout<<binaryToDecimal(str)<<"\n";
    return 0;
}