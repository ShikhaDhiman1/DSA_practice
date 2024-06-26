#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string infixToPostfix(string s)
{
    // Your code here
    map<char, int> mp = {
        {'^', 3},
        {'*', 2},
        {'/', 2},
        {'+', 1},
        {'-', 1}};
    stack<char> st;
    string str;

    for (char ch : s)
    {
        cout << ch << "\n";
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            str += ch;
        }
        else if (ch == '(')
            st.push(ch);
        else if (ch == ')')
        {
            while (st.top() != '(')
            {
                str += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while ((!st.empty()) && (mp[st.top()] >= mp[ch]))
            {
                str += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty())
    {
        str += st.top();
        st.pop();
    }
    return str;
}

int main()
{
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout << infixToPostfix(infix) << "\n";
    return 0;
}