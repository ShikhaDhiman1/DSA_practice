#include <iostream>
#include <string>
using namespace std;

bool isRotatedString(string s, string goal){
    int n = s.size();
    if(n != goal.size()) return false;
    for(int i = 0; i < s.size(); i++){
        string x = "";
        x += s[n - 1];
        s.pop_back();
        s.insert(0, x);

        if(s == goal){
            return true;
        }
    }
    return false;
}

bool isRotatedString2(string s, string goal){
    string temp = s + s;
    if(temp.find(goal) != string::npos) return true;
    return false;
}

int main(){
    string s = "abcdef";
    string goal = "cdefbb";
    cout<<isRotatedString(s, goal)<<"\n";
    cout<<isRotatedString2(s, goal)<<"\n";
    return 0;
}