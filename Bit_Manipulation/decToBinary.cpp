#include <iostream>
using namespace std;

string decToBinary(int n){
    string str = "";
    while(n != 0){
        if(n % 2 == 1){
            str += "1";
        }
        else str += "0";

        n = n / 2;
    }

    for(int i = 0; i < str.size() / 2; i++){
        swap(str[i], str[str.length() - i - 1]);
    }

    return str;
}
int main(){
    int n = 14;
    cout<<decToBinary(n)<<"\n";
    return 0;
}