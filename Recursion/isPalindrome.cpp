#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int i, string str){
    if(i >= str.length()/2) return true;

    if(toupper(str[i]) != toupper(str[str.length()-i-1])) return false;

    return(isPalindrome(i+1, str));
}

int main(){
    string x = "mAdAM";
    cout<<isPalindrome(0, x)<<endl;
    return 0;
}