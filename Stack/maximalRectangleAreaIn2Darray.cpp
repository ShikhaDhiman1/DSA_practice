#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestArea(vector<int> &heights)
{
    int n = heights.size();
    int maxArea = 0;
    stack<int> st;
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || heights[st.top()] > heights[i]))
        {
            int height = heights[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
            {
                width = i - st.top() - 1;
            }
            maxArea = max(maxArea, height * width);
        }

        st.push(i);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int ans = 0;
    vector<int> heights(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
                heights[j]++;
            else
                heights[j] = 0;
        }

        ans = max(ans, largestArea(heights));
    }
    return ans;
}

int main()
{
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout<<maximalRectangle(matrix)<<'\n';
    return 0;
}