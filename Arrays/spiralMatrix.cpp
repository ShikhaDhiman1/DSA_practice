#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>&matrix) {
    // Write your code here.
    vector<int> ans;

    int n = matrix.size();
    int m = matrix[0].size();

    int left = 0, right = m - 1;
    int top = 0, bottom = n-1;

    while(left <= right && top <= bottom){
        for(int j = left; j <= right; j++){
            ans.push_back(matrix[top][j]);
        }
        top++;
        for(int i = top; i <= bottom; i++){
            ans.push_back(matrix[i][right]);
        }
        right--;

        if(top <= bottom){
            for(int j = right; j >= left; j--){
                ans.push_back(matrix[bottom][j]);
            }
            bottom--;
        }

        if(left <= right){
            for(int i = bottom; i >= top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> mat = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    vector<int> res = spiralMatrix(mat);
    for(auto x : res){
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}