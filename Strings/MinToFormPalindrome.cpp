#include <iostream>
#include <string>
using namespace std;

int countMin(string str)
{
    int n = str.length();
    string temp;

    for (int i = n - 1; i >= 0; i--)
    {
        temp.push_back(str[i]);
    }
    cout << temp << "\n";
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        if (temp.find(str.substr(0, i + 1)) != string::npos)
        {
            len = max(len, i + 1);
        }
        else
            break;
    }
    return n - len;
}

int main()
{
    string s = "abcd";
    cout<<countMin(s)<<"\n";
    return 0;
}