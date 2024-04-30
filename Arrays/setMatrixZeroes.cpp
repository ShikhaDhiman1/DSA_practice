#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<bool> row(n, false), col(m, false);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 0){
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(row[i] || col[j]){
                matrix[i][j] = 0;
            }
        }
    }
}

void setZeroes2(vector<vector<int>> &matrix){
    // Use oth row and 0th column to keep track of rows and columns,respectively, containing zero
    int n = matrix.size();
    int m = matrix[0].size();

    int col0 = -1; // to keep track if any item in column 0 is 0

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0; // to track which row contains zero
                if(j != 0){
                    matrix[0][j] = 0; // to track which column contains zero(except column 0 bcz if we are using matrix[0][0] to show zero elements in 0th row, matrix[0][0] cannot be used to show if column 0 contains zero)
                }else{
                    col0 = 0;
                }
            }
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(matrix[i][j] != 0){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
    if(matrix[0][0] == 0){ // set row 0 elements to 0
        for(int j = 1; j < m; j++){
            matrix[0][j] = 0;
        }
    }
    if(col0 == 0){ // set column 0th elements to 0
        for(int i = 0; i < n; i++){
            matrix[i][0] = 0;
        }
    }
}

int main(){
    vector<vector<int>> matrix = {{1, 0, 2}, {9, 1, 7}, {0, 5, 3}};
    for(auto vec : matrix){
        for(auto x : vec){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    setZeroes(matrix);

    for(auto vec : matrix){
        for(auto x : vec){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";

    matrix = {{1, 2, 3, 4}, {8, 0, 7, 0}, {0, 5, 6, 2}};
    for(auto vec : matrix){
        for(auto x : vec){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    setZeroes2(matrix);

    for(auto vec : matrix){
        for(auto x : vec){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";

    return 0;
}
