#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.*/

int largestRectangleArea(vector<int> &heights){
    int n = heights.size();
    if(n == 1) return heights[0];

    int ans = 0;

    for(int i = 0; i<  n; i++){
        int j = i + 1;
        int maxArea = heights[i];

        while(j < n && heights[i] <= heights[j]){
            maxArea += heights[i];
            j++;
        }
        j = i - 1;
        while(j >= 0 && heights[i] <= heights[j]){
            maxArea += heights[i];
            j--;
        }
        ans = max(ans, maxArea);
    }

    return ans;
}
int largestRectangleArea2(vector<int> &heights){
    int n = heights.size();
    if(n == 1) return heights[0];

    stack<int> st;
    vector<int> minLeft(n), minRight(n);

    for(int i = 0; i < n; i++){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }
        if(st.empty()) minLeft[i] = 0;
        else minLeft[i] = st.top() + 1;

        st.push(i);
    }

    st = stack<int>();
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }
        if(st.empty()) minRight[i] = n - 1;
        else minRight[i] = st.top() - 1;

        st.push(i);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, ((minRight[i] - minLeft[i] + 1) * heights[i]));
    }

    return ans;
}

int largestRectangleArea3(vector<int> &heights){
    stack<int> st;
    int n = heights.size();
    int maxArea = 0;
    for(int i = 0; i <= n; i++){
        while(!st.empty() && (i == n || heights[st.top()] > heights[i])){
            int height = heights[st.top()];
            st.pop();
            int width;
            if(st.empty()) width = i;
            else width = i - st.top() - 1;
            maxArea = max(maxArea, width * height);
        }
        st.push(i);
    }

    return maxArea;
}
int main(){
    vector<int> heights = {2,1,5,6,2,3,1};
    cout<<largestRectangleArea(heights)<<"\n";
    cout<<largestRectangleArea2(heights)<<"\n";
    cout<<largestRectangleArea3(heights)<<"\n";
    return 0;
}