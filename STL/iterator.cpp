#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {10, 20, 40, 50};
    // (I)
    cout<<"iterator:\n";
    vector<int>::iterator it;

    for(it = v.begin(); it != v.end(); it++){
        cout<<*(it)<<" ";
    }
    cout<<"\n";
    vector<int>::reverse_iterator rit;
    for(rit = v.rbegin(); rit != v.rend(); rit++){
        cout<<*(rit)<<" ";
    }
    //(II)
    cout<<"\n\n'auto' keyword: \n";

    for(auto it = v.begin(); it != v.end(); it++){
        cout<<*(it)<<" ";
    }
    //(III)
    cout<<"\n\nfor-each loop: \n";
    
    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<"\n";
    cout<<*(v.end()-1)<<endl;
    return 0;
}