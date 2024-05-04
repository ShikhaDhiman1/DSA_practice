#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// BRUTE FORCE:---------------------------->>>>>>>>>>>>>>>>>
void rotateMatrix(vector<vector<int>> &mat){
    int n = mat.size();

    vector<vector<int>> ans(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans[j][n - i -1] = mat[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mat[i][j] = ans[i][j];
        }
    }
}

void rotateMatrix2(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();

    vector<int> vec;

    for(int j = 0; j < m; j++){
        for(int i = n-1; i >= 0; i--){
            vec.push_back(mat[i][j]);
        }
    }

    int k = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mat[i][j] = vec[k];
            k++;
        }
    }

    return;
}

void rotateMatrix3(vector<vector<int>> &mat){
    int n = mat.size();

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }

    for(int i = 0; i < n; i++){
        reverse(mat[i].begin(), mat[i].end());
    }
}

int main(){
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // rotateMatrix(matrix);
    // for(auto vec : matrix){
    //     for(auto x : vec){
    //         cout<<x<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"\n";

    // rotateMatrix2(matrix);
    // for(auto vec : matrix){
    //     for(auto x : vec){
    //         cout<<x<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"\n";

    rotateMatrix3(matrix);
    for(auto vec : matrix){
        for(auto x : vec){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    return 0;
}