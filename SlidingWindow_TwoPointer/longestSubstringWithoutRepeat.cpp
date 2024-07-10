#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s){
    int n = s.length();
    if(n == 0 || n == 1) return n;
    int maxLen = 0;

    for(int i = 0; i < n; i++){
        map<char, int> mp;
        for(int j = i; j <= n; j++){
            if(mp.find(s[j]) != mp.end() || j == n){
                maxLen = max(maxLen, j - i);
                break;
            }
            mp[s[j]]++;
        }
    }

    return maxLen;
}

int lengthOfLongestSubstring2(string s)
{
    int n = s.size();
    if(n == 0 || n == 1) return n;

    vector<int> mpp(128, -1);
    int l = 0, r = 0;
    int maxLen = 0;

    while(r < n){
        if(mpp[s[r]] != -1){
            l = max(l, mpp[s[r]] + 1);
        }
        maxLen = max(maxLen, r - l + 1);
        mpp[s[r]] = r;
        r++;
    }
    return maxLen;
}

int lengthOfLongestSubstring3(string s){
    int n = s.length();
    if(n == 0 || n == 1) return n;

    int l = 0, maxLen = 0;
    unordered_set<int> st;

    for(int r = 0; r < n; r++){
        while(st.find(s[r]) != st.end()){
            st.erase(s[l]);
            l++;
        }
        maxLen = max(maxLen, r - l + 1);
        st.insert(s[r]);
    }

    return maxLen;
}

int main(){
    string s = "tmmzuxt";
    cout<<lengthOfLongestSubstring(s)<<"\n";
    cout<<lengthOfLongestSubstring2(s)<<"\n";
    cout<<lengthOfLongestSubstring3(s)<<"\n";

    return 0;
}