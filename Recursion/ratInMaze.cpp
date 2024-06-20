#include <iostream>
#include <vector>
using namespace std;

void getPaths(int i, int j, int n, vector<vector<int>> &maze, vector<string> &ans, vector<vector<int>> &visited, string path){
    if(i == n - 1 && j == n - 1){
        ans.push_back(path);
        return;
    }
    visited[i][j] = 1;
    if(i + 1 < n && maze[i + 1][j] && !visited[i + 1][j]){
        getPaths(i + 1, j, n, maze, ans, visited, path + 'D');
    }

    if(j - 1 >= 0 && maze[i][j - 1] && visited[i][j- 1]){
        getPaths(i, j - 1, n, maze, ans, visited, path + 'L');
    }

    if(j + 1 < n && maze[i][j + 1] && !visited[i][j + 1]){
        getPaths(i, j + 1, n, maze, ans, visited, path + 'R');
    }

    if(i - 1 >= 0 && maze[i - 1][j] && !visited[i - 1][j]){
        getPaths(i - 1, j, n, maze, ans, visited, path + 'U');
    } 
    visited[i][j] = 0;
}
vector<string> findPaths(vector<vector<int>> &maze, int n){
    vector<string> ans;
    vector<vector<int>> visited(n, vector<int>(n, 0));

    getPaths(0, 0, n, maze, ans, visited, "");

    return ans;
}

int main(){
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}
    };

    vector<string> ans;
    findPaths(maze, 4);

    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}