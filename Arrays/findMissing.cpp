#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findMissing(int a[], int b[], int n, int m) 
	{ 
	    vector<int>res;
	    
	    unordered_map<int, int> mp;
	    
	    for(int i = 0; i < m; i++){
	        mp[b[i]]++;
	    }

	    for(int i = 0; i < n; i++){
	        if(mp[a[i]] == 0) res.push_back(a[i]);
	    }

        return res;
	} 

int main(){
    int a[] = {1, 2, 3, 4, 5, 10};
    int b[] = {2, 3, 1, 0, 5};

    vector<int> ans = findMissing(a, b, 6, 5);

    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;

}