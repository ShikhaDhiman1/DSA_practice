#include <iostream>
#include <string>
#include <climits>
using namespace std;

int myAtoi(string s){
    int i = 0;
    int neg = 1;
    long ans = 0;
    int n = s.length();
    while(i < n && s[i] == ' ') i++;

    if(s[i] == '-'){
        neg = -1;
        i++;
    }
    else if(s[i] == '+') i++;

    while((i < n) && (s[i] >= '0' && s[i] <= '9')){
        ans = ans * 10 + (s[i] - '0');
        if(ans >= INT_MAX && neg == -1) return INT_MIN;
        if(ans >= INT_MAX && neg == 1) return INT_MAX;
        i++;
    }

    return ans * neg;
}

int aToi(string s, int i, long int ans, int neg){
    if(i >= s.length()) return ans * neg;

    if(i < s.length() && (s[i] >= '0' && s[i] <= '9')){
        ans = ans * 10 + (s[i] - '0');
        if(ans >= INT_MAX && neg == -1) return INT_MIN;
        if(ans >= INT_MAX && neg == 1) return INT_MAX;
    }
    else return ans * neg;

    return aToi(s, i + 1, ans, neg);
}

int myAtoi2(string s){
    int i = 0;
    int neg = 1;
    while(i < s.length() && s[i] == ' ') i++;
    if(s[i] == '-'){
        i++;
        neg = -1;
    }
    else if(s[i] == '+') i++;

    return aToi(s.substr(i), 0, 0, neg);
}

int main(){
    string s = "  -0172+1";
    cout<<myAtoi(s)<<"\n";
    cout<<myAtoi2(s)<<"\n";
    return 0;
}