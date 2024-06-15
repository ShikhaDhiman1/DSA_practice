#include <iostream>
#include <string>
using namespace std;

/*Given an integer, K. Generate all binary strings of size k without consecutive 1’s.*/

void genBinaryStrings(int i, int k, string s){
    if(k == 0) return;
    if(i == k){
        cout<<s<<" ";
        return;
    }

    if(s[i - 1] == '1'){
        s += '0';
        genBinaryStrings(i + 1, k , s);
    }
    else if(s[i - 1] == '0'){
        s += '0';
        genBinaryStrings(i + 1, k, s);
        s.pop_back();
        s += '1';
        genBinaryStrings(i + 1, k, s);
    }
}
int main(){
    int k = 3;
    string s = "";
    s += '0';
    genBinaryStrings(1, k, s);
    s.pop_back();

    s += '1';
    genBinaryStrings(1, k, s);
    return 0;
}