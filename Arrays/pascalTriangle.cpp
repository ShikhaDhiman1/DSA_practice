#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> getPascalTriangle(int n){
    vector<vector<int>> ans(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || i == j){
                ans[i].push_back(1);
            }else{
                ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            }
        }
    }

    return ans;
}

int nCr(int n, int r){
    int res = 1;
    for(int i = 0; i < r; i++){
        res *= (n - i);
        res /= (i + 1); // res = (n/1)*((n-1)/2)*((n-2)/3).......*((n-r+1)/r)
    }
    return res;
}

void printPascalTriangleElement(int r, int c){
    cout<<nCr(r-1, c-1)<<"\n";
}

void printPascalTriangleRow(int r){
    for(int c = 0; c < r; c++){
        cout<<nCr(r-1, c)<<" ";
    }
    cout<<"\n";
}

int main(){
    int n = 6;
    vector<vector<int>> pTriangle = getPascalTriangle(n);
    for(auto vec : pTriangle){
        for(auto x : vec){
            cout<<x<<" ";
        }
        cout<<"\n";
    }

    int r = 5, c = 3;
    printPascalTriangleElement(r, c);
    printPascalTriangleRow(r);
    return 0;
}