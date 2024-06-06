#include <iostream>
#include <string>
#include <climits>
#include <map>
using namespace std;

int getBeautySum(map<char, int> &mp){
    int maxFreq = 0, minFreq = INT_MAX;
    for(auto it : mp){
        if(it.second > maxFreq) maxFreq = it.second;
        if(it.second < minFreq) minFreq = it.second;
    }
    return (maxFreq - minFreq);
}
int beautySum(string s){
    int sum = 0;
    for(int i = 0; i < s.size(); i++){
        map<char, int> mp;
        for(int j = i; j < s.size(); j++){
            mp[s[j]]++;
            if(mp.size() == 1) continue;
            sum += getBeautySum(mp);
        }
    }
    return sum;
}

int beautySum(string s){
    int sum = 0;
    for(int i = 0; i < s.size(); i++){
        map<char, int> mp;
        for(int j = 0; j < s.size(); j++){
            mp[s[j]]++;
            int maxFreq = 0, minFreq = INT_MAX;

            for(auto it : mp){
                if(it.second > maxFreq) maxFreq = it.second;
                if(it.second < minFreq) minFreq = it.second;
            }
            sum += (maxFreq - minFreq);
        }
    }
    return sum;
}

int main(){
    return 0;
}