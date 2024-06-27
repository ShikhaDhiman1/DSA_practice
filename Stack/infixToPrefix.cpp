#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '-' || ch == '+')
        return 1;
    return -1;
}

string infixToPrefix(string s)
{
    stack<char> st;
    string ans = "";
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }
    s = "(" + s + ")";
    for (auto ch : s)
    {
        if (ch == '(')
            st.push(ch);

        else if (ch == '^' || ch == '*' || ch == '/' || ch == '-' || ch == '+')
        {
            if (ch == '^')
            {
                while (precedence(ch) <= precedence(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            else
            {
                while ((precedence(st.top()) > precedence(ch)))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(ch);
        }

        else if (ch == ')')
        {
            while (st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            ans += ch;
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string infix = "(a/b+c)-(d+e*f)";
    cout << infixToPrefix(infix) << "\n";
    return 0;
}