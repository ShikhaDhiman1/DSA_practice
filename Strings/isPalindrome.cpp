#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0; 
        int end = s.length() - 1;
        while(start < end){
            if(!isalnum(s[start])){
                start++;
            }
            else if(!isalnum(s[end])){
                end--;
            }
            else if(tolower(s[start]) != tolower(s[end])){
                return false;
            }
            else{
                start++;
                end--;
            }
        }

        return true;
    }
};

int main(){
    Solution s1;
    cout<<s1.isPalindrome("A man, a plan, a canal: Panama")<<endl;
    cout<<tolower('0')<<endl;
    return 0;
}