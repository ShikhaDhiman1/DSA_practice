#include <iostream>
#include <map>
#include <string>
using namespace std;

int romanToInt(string s) {
    int num = 0;
    int i = 0;
    int n = s.size();
    while(i < n){
        if(s[i] == 'I'){
            if((i + 1) < n && (s[i + 1] == 'V' || s[i + 1] == 'X')){
                num -= 1;
            }
            else{
                num += 1;
            }
        }
        else if(s[i] == 'V') num += 5;
        else if(s[i] == 'X'){
            if((i + 1) < n && (s[i + 1] == 'L' || s[i + 1] == 'C')){
                num -= 10;
            }
            else{
                num += 10;
            }
        }
        else if(s[i] == 'L') num += 50;
        else if(s[i] == 'C'){
            if((i + 1) < n && (s[i + 1] == 'D' || s[i + 1] == 'M')){
                num -= 100;
            }
            else{
                num += 100;
            }
        }
        else if(s[i] == 'D') num += 500;
        else if(s[i] == 'M') num += 1000;
        i++;
    }
    return num;
}

int romanToInt2(string s){
    map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        if(mp[s[i]] < mp[s[i + 1]]){
            ans -= mp[s[i]];
        }
        else{
            ans += mp[s[i]];
        }
    }
    return ans;
}

int main(){
    string s = "MCMXCIV";
    cout<<romanToInt(s)<<"\n";
    cout<<romanToInt2(s)<<"\n";
    return 0;
}