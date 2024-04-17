#include <iostream>
#include <map>
using namespace std;

int main(){
    map<char, int> mp;

    string str;
    cout<<"Enter the string : ";
    cin>>str;

    for(auto ch:str){
        mp[ch]++;
    }

    for(auto it : mp){
        cout<<it.first<<" -> "<<it.second<<"\n";
    }
    cout<<"\n";
    
    int hash[256] = {0};

    for(int i = 0; i < str.length(); i++){
        hash[str[i]]++;
    }

    for(auto ch : str){
        cout<<ch<<" -> "<<hash[ch]<<"\n";
    }
    cout<<"\n";
    return 0;
}