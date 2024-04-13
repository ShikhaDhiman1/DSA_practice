#include <bits/stdc++.h>
using namespace std;

int reverse(int x) {
    vector <int> v;
    int num = x;
    // string str="";
    if(num < 0){
        // str += "-";
        num *= (-1);
    }
    // if(x < 0) cout<<"-";
    while(num != 0){
        cout<<num<<endl;
        int r = num%10;
        v.push_back(r);
        num = num/10;
    }
    int n = 0;
    for(int i = 0; i < v.size(); i++){
        // cout<<str<<endl;
        // str += to_string(v[i]);
        n += v[i] * pow(10, (v.size() - i - 1));
        // return v[i];
    }
    // cout<<"skkhjk\n";
    // int ans = stoi(str);
    // return ans;
    if(x<0) return ((-1)*n);
    else return n;
}

int reverse2(int x){
    vector <int> v;
    int num = x;
    if(num < 0){
        // str += "-";
        cout<<"-";
        num *= (-1);
    }
    // if(x < 0) cout<<"-";
    while(num != 0){
        // cout<<num<<endl;
        int r = num%10;
        v.push_back(r);
        num = num/10;
    }
    for(int i = 0; i < v.size()-1; i++){
        cout<<v[i];
    }
    return v[v.size() - 1];

}
// Optimized: ACCEPTED in leetcode----->
int reverse3(int x){
    int start = 0;
    if(x < 0) start = 1;
    string str = to_string(abs(x));
    for(int i = 0; i < str.length()/2; i++){
        swap(str[i], str[str.length() - i - 1]);
    }
    int ans;
    stringstream mystream;
    mystream << str;
    mystream >> ans;
    // int ans = stoi(str);
    if(ans == INT_MIN || ans == INT_MAX) return 0;

    if(start) return ((-1)*ans);
    else return ans;
}

int main(){
    int num = 10011;
    string s = "-123345";
    cout<<reverse3(num);
    cout<<stoi(s)<<endl;
    cout<<INT_MAX<<endl;
    return 0;
}