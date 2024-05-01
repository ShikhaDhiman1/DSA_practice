#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat){
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

int main(){
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotateMatrix(matrix);
    for(auto vec : matrix){
        for(auto x : vec){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    return 0;
}