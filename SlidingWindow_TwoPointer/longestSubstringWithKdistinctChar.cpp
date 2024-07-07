#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int longestSubstring(string s, int k){
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        unordered_map<char, int> mp;
        for(int j = i; j < s.size(); j++){
            mp[s[j]]++;
            if(mp.size() <= k){
                ans = max(ans, j - i + 1);
            }
            else break;
        }
    }
    return ans;
}

int longestSubstring2(string s, int k){
    int ans = 0;
    int l = 0, r = 0;
    unordered_map<char, int> mp;

    while(r < s.length()){
        mp[s[r]]++;
        while(mp.size() > k){
            mp[s[l]]--;
            if(mp[s[l]] == 0){
                mp.erase(s[l]);
            }
            l++;
        }
        if(mp.size() <= k){
            ans = max(ans, r - l + 1);
        }
        r++;
    }

    return ans;
}

int longestSubstring3(string s, int k){
    int ans = 0;
    int l = 0, r = 0;
    unordered_map<char, int> mp;

    while(r < s.length()){
        mp[s[r]]++;
        if(mp.size() > k){
            mp[s[l]]--;
            if(mp[s[l]] == 0) mp.erase(s[l]);
            l++;
        }
        else{
            ans = max(ans, r - l + 1);
        }
        r++;
    }
    return ans;
}

int main(){
    string s = "vaacbdbbcd";
    int k = 3;
    cout<<longestSubstring(s, k)<<"\n";
    cout<<longestSubstring2(s, k)<<"\n";
    cout<<longestSubstring3(s, k)<<"\n";
    
    return 0;
}