#include <iostream>
#include <vector>
using namespace std;

vector<int> printNos(int x) {
    vector<int> ans;

    if(x < 1) return ans;

    ans.push_back(x);

    vector<int> res = printNos(x-1);
    ans.insert(ans.end(), res.begin(), res.end());
    
    return ans;
}


int main(){
    vector<int> result = printNos(5);
    for(auto it : result){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}