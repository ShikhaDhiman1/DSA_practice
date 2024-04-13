#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <cmath>
#include<typeinfo>
using namespace std;

int main(){
    unordered_set <string> set1;

    set1.insert("one");

    vector<string> arrStr = {"two", "three", "four"};
    set1.insert(arrStr.begin(), arrStr.end());
    set1.insert("one");

    for(auto it : set1){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<"\nset1.insert('two').second: "<<set1.insert("two").second<<endl;
    cout<<"*(set1.insert('two').first): "<<*(set1.insert("two").first)<<endl<<endl;

    cout<<"set1.insert('five').second: "<<set1.insert("five").second<<endl;
    cout<<"*(set1.insert('five').first): "<<*(set1.insert("five").first)<<endl<<endl;

    for(auto it : set1){
        cout<<it<<" ";
    }
    cout<<endl;

    cout<<*(set1.find("one"))<<endl;

    if(set1.find("hone") != set1.end()){
        cout<<"Element found!\n";
    }
    else{
        cout<<"Element not found!\n";
    }

    set1.erase("one");
    for(auto it : set1){
        cout<<it<<" ";
    }
    cout<<endl;

    set1.erase(set1.find("three"), set1.end());
    for(auto it : set1){
        cout<<it<<" ";
    }
    cout<<endl;

    cout<<(floor(-123/10))<<endl;

    cout<<to_string(123).length()<<endl;
    int t = 123;
    cout<<typeid(t).name()<<endl;
    to_string(t);
    cout<<typeid(t).name()<<endl;

    return 0;
}