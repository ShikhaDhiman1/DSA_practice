#include <iostream>
#include <string>
using namespace std;

int maxDepth(string s){
    int count = 0;
    int max_depth = 0;

    for(auto ch : s){
        if(ch == '(') count++;
        else if(ch == ')'){
            max_depth = max(max_depth, count);
            count--;
        }
    }
    return max_depth;
}

int main(){
    string s = "(1 + (2 + ((8 / 4)))) + 1";
    cout<<maxDepth(s)<<"\n";
    return 0;
}