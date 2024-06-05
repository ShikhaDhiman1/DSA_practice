#include <iostream>
#include <string>
using namespace std;

string largestOdd(string num){
    if((num[num.size() - 1] - '0') % 2 == 1) return num;

    string temp = "", ans = "";

    for(auto ch : num){
        temp += ch;
        if((ch - '0') % 2 == 1){
            ans = temp;
        }
    }
    return ans;
}

string largestOdd2(string num){
    for(int i = num.size(); i >= 0; i--){
        if((num[i] - '0') % 2 == 1){
            return num.substr(0, i + 1);
        }
    }

    return "";
}

int main(){
    string num = "567892";
    cout<<largestOdd(num)<<"\n";
    cout<<largestOdd2(num)<<"\n";
    return 0;
}